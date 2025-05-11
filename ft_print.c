/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 22:10:09 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/11 18:20:17 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void	ft_printf(char *s, ...)
{
	size_t	len;
	int		error;
	t_flags	flags;
	va_list	ap;

	va_start(ap, s);
	len = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			ft_reset_flags(&flags);
			ft_get_flags(s, &flags, &error);
			ft_lst_add_arg();
		}
		else
		{
			s_end = ft_find_s_end(s);
			len = s_end - s;
			ft_printn(s, len);
			s = s_end;
		}
	}
	va_end(ap);
}

static t_list	*ft_lst_malloc_content(t_list **lst, char *s, size_t s_len);
static void	ft_del_content(t_content *content);

char	*ft_lst_add_arg(t_list **lst, va_list ap, \
						t_flags *flags, char *s)
{
	;
}

// get's the next % or '\0' if not found
char	*ft_lst_add_str(t_list **lst, char *s)
{
	char		*s_end;
	size_t		s_len;

	s_end = ft_strchr(s, '%');
	if (s_end == NULL)
		return (ft_strchr(s, '\0'));
	if (*(s_end + 1) == '%')
		s_end += 2;
	s_len = s_end - s;
	
	return (s_end);
}

static t_list	*ft_lst_malloc_content(t_list **lst, char *s, size_t s_len)
{
	char		*new_str;
	t_content	*new_content;
	t_list		*new_node;
	
	new_str = ft_str_mallocpy(s, s_len);
	if (!new_str)
		return (NULL);
	new_content = malloc(sizeof(*new_content));
	if (!new_content)
		return (free(new_str), NULL);
	new_node = ft_lstnew(new_content);
	if (!new_node)
		return (ft_del_content(new_content), NULL);
	ft_lstadd_back(lst, ft_lstnew());
	ft_lstdelone();
}

static void	ft_del_content(t_content *content)
{
	free(content->s);
	free(content);
}

void	ft_printn(char *s, size_t len)
{
	write(1, s, len);
}
