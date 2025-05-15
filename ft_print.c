/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/15 17:31:00 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"
#include "ft_printf.h"
#include "libft.h"
#include "ft_arrlst.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

static char	*ft_arrlst_add_arg_get_str(va_list ap, t_flags *flags);

int	ft_printf(char *s, ...)
{
	int			error;
	t_flags		flags;
	va_list		ap;
	t_arrlst	*arrlst;

	arrlst = ft_arrlst_create(10, 0);
	if (!arrlst)
		return (NULL);
	va_start(ap, s);
	ft_printf_helpr(s, arrlst, error, flags, ap);
	va_end(ap);
}

int	ft_printf_helpr(char *s, t_arrlst *arrlst, int error, \
					t_flags flags, va_list ap)
{
	while (*s)
	{
		if (*s == '%')
		{
			ft_reset_flags(&flags);
			s = ft_get_flags(s, &flags, &error);
			ft_arrlst_add_arg(&arrlst, ap, &flags);
		}
		else
		{
			s_end = ft_find_s_end(s);
			len = s_end - s;
			ft_printn(s, len);
			s = s_end;
		}
	}
}

t_arrlst *ft_arrlst_add_arg(t_arrlst **arrlst, va_list ap, t_flags *flags)
{
	char	*str;

	str = ft_arrlst_add_arg_get_str(ap, flags);
	if (!str)
		return (ft_arrlst_free(arrlst, free), NULL);
	if (!ft_arrlst_append_flag_strs(arrlst, *flags, str))
		return (NULL);
	return (*arrlst);
}

static char	*ft_arrlst_add_arg_get_str(va_list ap, t_flags *flags)
{
	char	*str;

	if (flags->type == 'c')
		str = ft_ctostr(va_arg(ap, char));
	if (flags->type == 's')
		str = ft_strtoa(va_arg(ap, char *));
	if (flags->type == 'p')
		str = ft_ptoa(va_arg(ap, void *));
	if (flags->type == 'i')
		str = ft_itoa_base_signed(va_arg(ap, char *), "0123456789", (flags->nbr_neg));
	if (flags->type == 'u')
		str = ft_itoa_base_unsigned(va_arg(ap, char *), "0123456789");
	if (flags->type == 'x')
		str = ft_itoa_base_unsigned(va_arg(ap, char *), "0123456789abcdef");
	if (flags->type == 'X')
		str = ft_itoa_base_unsigned(va_arg(ap, char *), "0123456789ABCDEF");
	if (flags->type == '%')
		str = ft_strdup("%");
	return (str);
}

// get's the next % or '\0' if not found
// and mallocs the str into arrlst
char	*ft_arrlst_append_str(t_arrlst **lst, char *s)
{
	char		*s_end;
	size_t		s_len;

	s_end = ft_strchr(s, '%');
	if (s_end == NULL)
		return (ft_strchr(s, '\0'));
	if (*(s_end + 1) == '%')
		s_end += 2;
	s_len = s_end - s;
	return (s_end);
}
