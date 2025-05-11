/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_helpers.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/11 17:32:11 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/11 17:38:58 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdint.h"

// (ft_itoa_base.c)
char	*ft_itoa_base_signed(int val, const char *base, bool *sign);
char	*ft_itoa_base_unsigned(uintptr_t val, const char *base);

// (ft_set_flags/2.c)
char	*ft_get_flags(char *s, t_flags *flags, int *error);

// (ft_printf.c)
void	ft_reset_flags(t_flags *flags);