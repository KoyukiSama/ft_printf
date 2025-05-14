/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/14 12:07:49 by kclaes        ########   odam.nl         */
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

void	ft_printf(char *s, ...)
{
	size_t	len;
	int		error;
	t_flags	flags;
	va_list	ap;

	va_start(ap, s);
	len = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			ft_reset_flags(&flags);
			ft_get_flags(s, &flags, &error);
			ft_lst_add_arg();
		}
		else
		{
			s_end = ft_find_s_end(s);
			len = s_end - s;
			ft_printn(s, len);
			s = s_end;
		}
	}
	va_end(ap);
}

char	*ft_arrlst_add_arg(t_arrlst **arrlst, va_list ap, t_flags *flags)
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
	if (!str)
		return (ft_arrlst_free(arrlst, free));
	if (flags->left_justf || flags->right_justf)
		
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

void	ft_printn(char *s, size_t len)
{
	write(1, s, len);
}
