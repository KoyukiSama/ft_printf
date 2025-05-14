/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_conversion.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 12:08:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/14 12:27:55 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>

// calculates how much justify 
char	*ft_justify_malloc(t_flags flags, char *str)
{
	int		justify_length;
	char	*justify;
	size_t	i;

	if (flags.left_justf)
		justify_length = flags.left_justf - ft_strlen(str) - flags.nbr_neg;
	else if (flags.right_justf)
		justify_length = flags.right_justf - ft_strlen(str) - flags.nbr_neg;
	if (justify_length <= 0)
		return (NULL);
	justify = malloc(justify_length + 1);
	if(!justify)
		return (NULL);
	i = 0;
	while (i < justify_length)
		justify[i++] = ' ';
	return (justify);
}

char	*ft_zeros_malloc(t_flags flags, char *str)
{
	
}
