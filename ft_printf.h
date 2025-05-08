/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:09:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/08 22:28:15 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// "      42" = right_justf
// "42      " = left_justf
// "00000042" = digits_width
// "-0000042" = nbr_width
typedef struct s_flags
{
	bool	right_justf;
	bool	left_justf;
	bool	digits_width;
	bool	nbr_width;
	bool	nbr_neg;
	bool	nbr_zero;
}	t_flags;
