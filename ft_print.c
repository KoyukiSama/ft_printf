/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/10 18:15:20 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void	ft_reset_flags(t_flags *flags);
char	*ft_get_flags(char *s, t_flags *flags);
char	*ft_itoa_base_signed(int val, char *base, bool *sign);
char	*ft_itoa_base_unsigned(unsigned int val, char *base);

void	ft_printf(char *s, ...)
{
	size_t	len;
	char	*s_end;
	t_flags	flags;

	while (*s)
	{
		if (*s == '%')
		{
			ft_reset_flags(&flags);
			
		}
		else
		{
			len = 0;
			s_end = ft_find_s_end(s);
			len = s_end - s;
			ft_printn(s, len);
			s = s_end;
		}
	}
}

// get's the next % or '\0' if not found
char	*ft_find_s_end(char *s)
{
	char	*s_prcnt;

	s_prcnt = ft_strchr(s, '%');
	if (s_prcnt == NULL)
		return (ft_strchr(s, '\0'));
	return (s_prcnt);
}

void	ft_printn(char *s, size_t len)
{
	write(1, s, len);
}
