/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:40:21 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/08 23:04:16 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_signed(int val, char *base, bool *sign)
{
	unsigned int	uval;
	
	if (val < 0)
	{
		uval = ((unsigned int) -(val + 1)) + 1;
		*sign = true;
	}
	else
		uval = (unsigned int) val;
	return (ft_itoa_base_unsigned(uval, base));
}

char	*ft_itoa_base_unsigned(unsigned int val, char *base)
{
	char	buffer[35];
	char	*str;
	
	str = buffer + (sizeof(buffer) - 1);
	*str = '\0';

	// TODO
}
