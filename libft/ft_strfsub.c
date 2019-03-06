/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfsub.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 19:13:05 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 19:13:16 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len--)
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	ft_strdel(&s);
	return (tab);
}
