/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/16 17:16:37 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_helpers.h"
#include "ft_printf.h"
#include "libft.h"
#include "ft_arrlst.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

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
	ft_printf_store_strs(s, arrlst, error, flags, ap);
	va_end(ap);
}

int	ft_printf_store_strs(char *s, t_arrlst *arrlst, int error, \
					t_flags flags, va_list ap)
{
	while (*s)
	{
		if (*s == '%')
		{
			ft_reset_flags(&flags);
			s = ft_get_flags(s, &flags, &error);
			if (error)
				return (ft_putstr_fd(s, 1), ft_arrlst_free(&arrlst, free), \
						free(s), -1);
			if (!ft_arrlst_add_arg(&arrlst, ap, &flags))
				return (-1);
		}
		else
		{
			s = ft_arrlst_append_str(s);
			if (!s)
				return (-1);
		}
	}
}
