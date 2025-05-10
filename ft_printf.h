/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:09:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/10 15:09:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// "      42" = right_justf
// "42      " = left_justf
// "00000042" = perc_flag
// "-0000042" = 0_flag
typedef struct s_flags
{
	int		right_justf;
	int		left_justf;
	int		zeros_width;
	bool	zero_flag;
	bool	perc_flag;
	bool	nbr_neg;
	bool	nbr_zero;
}	t_flags;
