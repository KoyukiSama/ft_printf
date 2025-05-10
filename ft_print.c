/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/10 16:02:23 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void	ft_printf(char *s, ...)
{
	size_t	len;
	char	*s_end;

	len = 0;
	while (*s)
	{
		s_end = ft_find_s_end(s);
		
		len = s_prcnt - s;
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
