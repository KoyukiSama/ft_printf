/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 17:04:04 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 18:50:51 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_lst.h"
#include "ft_printf.h"
#include "printf_helpers.h"
#include <stdlib.h>
#include <stdarg.h>

static char	*ft_va_to_str(va_list ap, t_flags *flags);
static int	ft_extract_list_strs_len(t_list *lst);

t_list	*ft_lst_add_arg(t_list *lst, va_list ap, t_flags *flags)
{
	char	*str;

	str = ft_va_to_str(ap, flags);
	if (!str)
		return (NULL);
	if (!ft_lst_append_flag_strs(lst, *flags, str))
		return (NULL);
	return (lst);
}

static char	*ft_va_to_str(va_list ap, t_flags *flags)
{
	char	*str;

	if (flags->type == 'c')
		str = ft_ctoa(va_arg(ap, int));
	if (flags->type == 's')
		str = ft_strtoa(va_arg(ap, char *), *flags);
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
// and mallocs the str intolst 
char	*ft_lst_append_str(t_list *lst, char *s)
{
	char		*s_end;
	size_t		s_len;

	s_end = ft_strchr(s, '%');
	if (s_end == NULL)
		s_end = ft_strchr(s, '\0');
	s_len = s_end - s;
	if (!ft_lst_append(lst, ft_str_mallocpy(s, s_len)))
		return (NULL);
	return (s_end);
}

// returns parameter len: the length of the new malloced string
// returns char	*: string from all lst content entries
char	*ft_extract_list(t_list	*lst, int *len)
{
	size_t	i;
	int		j;
	char	*s_curr;
	char	*s_ret;

	*len = ft_extract_list_strs_len(lst);
	s_ret = malloc(*len + 1);
	if (!s_ret)
		return (NULL);
	i = 0;
	j = 0;
	while (j < *len)
	{
		s_curr = ft_lst_getc(lst, i);
		while (*s_curr)
			s_ret[j++] = *s_curr++;
		i++;
	}
	s_ret[j] = '\0';
	return (s_ret);
}

static int	ft_extract_list_strs_len(t_list *lst)
{
	size_t	i;
	int		len;
	size_t	lst_size;
	char	*str;

	i = 0;
	len = 0;
	lst_size = ft_lst_getsize(lst);
	while (i < lst_size)
	{
		str = ft_lst_getc(lst, i++);
		len += ft_strlen(str);
	}
	return (len);
}
