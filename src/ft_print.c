/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/18 18:56:51 by kclaes        ########   odam.nl         */
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

static int	ft_printf_store_strs(char *s, t_arrlst *arrlst, int error, \
						va_list ap);
static int	ft_printf_write(t_arrlst *arrlst);

int	ft_printf(char *s, ...)
{
	int			error;
	va_list		ap;
	t_arrlst	*arrlst;

	if (!s)
		return (-1);
	error = 0;
	arrlst = ft_arrlst_create(10, 0);
	if (!arrlst)
		return (-1);
	va_start(ap, s);
	if (!ft_printf_store_strs(s, arrlst, error, ap))
		return (va_end(ap), -1);
	va_end(ap);
	#include <stdio.h>
	int len = ft_arrlst_get_len(arrlst);
	for (int i = 0; i < len; i++)
		fprintf(stderr, "[%s]\n", ft_arrlst_get_i(arrlst, i));
	return (ft_printf_write(arrlst));
}

static int	ft_printf_store_strs(char *s, t_arrlst *arrlst, int error, \
									va_list ap)
{
	t_flags	flags;

	while (*s)
	{
		if (*s == '%')
		{
			ft_reset_flags(&flags);
			s = ft_get_flags(s, &flags, &error);
			if (error)
				return (ft_putstr_fd(s, 1), ft_arrlst_free(&arrlst, free), \
						free(s), 0);
			if (!ft_arrlst_add_arg(&arrlst, ap, &flags))
				return (0);
		}
		else
		{
			s = ft_arrlst_append_str(&arrlst, s);
			if (!s)
				return (0);
		}
	}
	return (1);
}

static int	ft_printf_write(t_arrlst *arrlst)
{
	char	*s_write;
	int		len;

	s_write = ft_extract_arrlst(arrlst, &len);
	if (!s_write)
		return (ft_arrlst_free(&arrlst, free), -1);
	ft_arrlst_free(&arrlst, free);
	len = write(1, s_write, len);
	free(s_write);
	return (len);
}
