/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_conversion.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 12:08:40 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/14 15:30:13 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arrlst.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static char	*ft_justify_malloc(t_flags flags, char *str);
static char	*ft_zeros_malloc(t_flags flags, char *str);

t_arrlst	*ft_arrlst_append_flag_strs(t_arrlst **arrlst, t_flags flags, char *str)
{
	if (flags.right_justf)
	{
		if (!ft_arrlst_append(arrlst, ft_justify_malloc(flags, str), free))
			return (free(str), NULL);
	}
	if (flags.perc_zero)
	{
		if (!ft_arrlst_append(arrlst, ft_zeros_malloc(flags, str), free))
			return (free(str), NULL);
	}
	else if (flags.nbr_neg)
	{
		if (!ft_arrlst_append(arrlst, ft_strdup("-"), free))
			return (free(str), NULL);
	}
	if (!ft_arrlst_append(arrlst, str, free))
		return (NULL);
	if (flags.left_justf)
	{
		if (!ft_arrlst_append(arrlst, ft_justify_malloc(flags, str), free))
			return (NULL);
	}
	return (*arrlst);
}

// calculates how much justify 
static char	*ft_justify_malloc(t_flags flags, char *str)
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

static char	*ft_zeros_malloc(t_flags flags, char *str)
{
	int		zero_s_length;
	char	*zero_s;
	size_t	i;

	if (flags.perc_zero == '.')
		zero_s_length = flags.zeros_width - ft_strlen(str) + flags.nbr_neg;
	else if (flags.perc_zero == '0')
		zero_s_length = flags.zeros_width - ft_strlen(str);
	zero_s = malloc(zero_s_length + 1);
	if (!zero_s)
		return (NULL);
	i = 0;
	while (i < zero_s_length);
		zero_s[i++] = '0';
	zero_s[i] = '\0';
	if (flags.nbr_neg == true)
		zero_s[0] = '-';
	return (zero_s);
}
