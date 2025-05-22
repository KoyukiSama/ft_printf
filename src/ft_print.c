/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/22 13:19:12 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_helpers.h"
#include "ft_printf.h"
#include "libft.h"
#include "ft_lst.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

static int	ft_printf_store_strs(char *s, t_list *lst, int error, va_list ap);
static int	ft_printf_write(t_list *lst);

int	ft_printf(char *s, ...)
{
	int		error;
	va_list	ap;
	t_list	*lst;

	if (!s)
		return (-1);
	error = 0;
	lst = ft_lst_create();
	if (!lst)
		return (-1);
	va_start(ap, s);
	if (!ft_printf_store_strs(s, lst, error, ap))
		return (ft_lst_free(&lst, free), va_end(ap), -1);
	va_end(ap);
	return (ft_printf_write(lst));
}

static int	ft_printf_store_strs(char *s, t_list *lst, int error, va_list ap)
{
	t_flags	flags;

	while (*s)
	{
		if (*s == '%')
		{
			ft_reset_flags(&flags);
			s = ft_get_flags(s, &flags, &error);
			if (error)
				return (ft_putstr_fd(s, 1), free(s), 0);
			if (!ft_lst_add_arg(lst, ap, &flags))
				return (0);
		}
		else
		{
			s = ft_lst_append_str(lst, s);
			if (!s)
				return (0);
		}
	}
	return (1);
}

static int	ft_printf_write(t_list *lst)
{
	char	*s_write;
	int		len;

	s_write = ft_extract_list(lst, &len);
	ft_lst_free(&lst, free);
	if (!s_write)
		return (-1);
	len = write(1, s_write, len);
	free(s_write);
	return (len);
}
