/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsntr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:44:28 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 19:45:02 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	find;

	i = 0;
	if (to_find[i] == '\0')
		return ((char*)str);
	while (str[i] && i < len)
	{
		find = 0;
		while (str[i + find] == to_find[find] && i + find < len)
		{
			find++;
			if (to_find[find] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
