/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_flags2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/10 18:07:00 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/10 19:19:24 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_flags *flags)
{
	flags->right_justf = 0;
	flags->left_justf = 0;
	flags->zeros_width = 0;
	flags->perc_zero = 0;
	flags->nbr_neg = 0;
	flags->nbr_zero = 0;
	flags->type = 0;
}
