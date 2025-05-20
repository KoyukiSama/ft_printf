/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_helpers.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/11 17:32:11 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/20 18:56:39 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPERS_H
# define PRINTF_HELPERS_H

# include "ft_lst.h"
# include "ft_printf.h"
# include "stdint.h"
# include <stdarg.h>

// (pf_sometoa.c)
char		*ft_itoa_base_signed(int val, const char *base, bool *sign);
char		*ft_itoa_base_unsigned(unsigned int val, const char *base);
char		*ft_strtoa(char *str, t_flags flags);
char		*ft_ptoa(void *p);
char		*ft_ctoa(char c);

// (pf_set_flags/2.c)
char		*ft_get_flags(char *s, t_flags *flags, int *error);

// (pf_printf.c)
void		ft_reset_flags(t_flags *flags);

// (pf_bonus_conversion.c)
t_list		*ft_lst_append_flag_strs(t_list **lst, t_flags flags, char *str);

// (pf_lst.c)
t_list		*ft_lst_add_arg(t_list **lst, va_list ap, t_flags *flags);
char		*ft_lst_append_str(t_list **lst, char *s);
char		*ft_extract_list(t_list	*lst, int *len);

#endif