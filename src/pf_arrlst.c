/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_arrlst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 17:04:04 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/17 16:14:14 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_arrlst.h"
#include "ft_printf.h"
#include "printf_helpers.h"
#include <stdlib.h>
#include <stdarg.h>

static char	*ft_arrlst_add_arg_get_str(va_list ap, t_flags *flags);
static int	ft_extract_arrlst_strs_len(t_arrlst *arrlst);

t_arrlst	*ft_arrlst_add_arg(t_arrlst **arrlst, va_list ap, t_flags *flags)
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
		str = ft_ctoa(va_arg(ap, int));
	if (flags->type == 's')
		str = ft_strtoa(va_arg(ap, char *));
	if (flags->type == 'p')
		str = ft_ptoa(va_arg(ap, void *));
	if (flags->type == 'i')
		str = ft_itoa_base_signed(va_arg(ap, int), "0123456789", \
									&(flags->nbr_neg));
	if (flags->type == 'u')
		str = ft_itoa_base_unsigned(va_arg(ap, int), "0123456789");
	if (flags->type == 'x')
		str = ft_itoa_base_unsigned(va_arg(ap, int), "0123456789abcdef");
	if (flags->type == 'X')
		str = ft_itoa_base_unsigned(va_arg(ap, int), "0123456789ABCDEF");
	if (flags->type == '%')
		str = ft_strdup("%");
	return (str);
}

// get's the next % or '\0' if not found
// and mallocs the str into arrlst
char	*ft_arrlst_append_str(t_arrlst **arrlst, char *s)
{
	char		*s_end;
	size_t		s_len;

	s_end = ft_strchr(s, '%');
	if (s_end == NULL)
		s_end = ft_strchr(s, '\0');
	s_len = s_end - s;
	if (!ft_arrlst_append(arrlst, ft_str_mallocpy(s, s_len), free))
		return (NULL);
	return (s_end);
}

// returns parameter len: the length of the new malloced string
// returns char	*: string from all arrlst content entries
char	*ft_extract_arrlst(t_arrlst	*arrlst, int *len)
{
	size_t	i;
	int		j;
	char	*s_curr;
	char	*s_ret;

	*len = ft_extract_arrlst_strs_len(arrlst);
	s_ret = malloc(*len + 1);
	if (!s_ret)
		return (ft_arrlst_free(&arrlst, free), NULL);
	i = 0;
	j = 0;
	while (j < *len)
	{
		s_curr = ft_arrlst_get_i(arrlst, i);
		while (*s_curr)
			s_ret[j++] = *s_curr++;
		i++;
	}
	s_ret[j] = '\0';
	return (s_ret);
}

static int	ft_extract_arrlst_strs_len(t_arrlst *arrlst)
{
	size_t	i;
	int		len;
	char	*s_curr;

	s_curr = ft_arrlst_get_i(arrlst, 0);
	i = 1;
	len = 0;
	while (s_curr)
	{
		len += ft_strlen(s_curr);
		s_curr = ft_arrlst_get_i(arrlst, i);
		i++;
	}
	return (len);
}
