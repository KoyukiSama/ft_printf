/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:09:39 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/11 16:24:41 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>

# define HEX_UPP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define DEC "0123456789"
# define RED "\033[31m"
# define RESET "\033[0m"

// "      42" = right_justf
// "42      " = left_justf
// "00000042" = perc_flag
// "-0000042" = 0_flag
typedef struct s_flags
{
	int		right_justf;
	int		left_justf;
	int		zeros_width;
	char	perc_zero;
	bool	nbr_neg;
	bool	nbr_zero;
	char	type;
}	t_flags;

#endif