/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strfjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 15:39:03 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 17:20:51 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char const *s1, char const *s2)
{
	char			*tab;
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	if (!(s1 && s2) || !(tab = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	while (s1[a])
	{
		tab[b] = s1[a];
		a++;
		b++;
	}
	a = 0;
	while (s2[a])
	{
		tab[b] = s2[a];
		a++;
		b++;
	}
	tab[b] = '\0';
	free((void *)s1);
	return (tab);
}
