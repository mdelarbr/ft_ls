/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:40:15 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 17:22:06 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*tab;
	unsigned int	a;
	unsigned int	b;

	a = 0;
	b = 0;
	if (!(s1 && s2) || !(tab = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
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
	return (tab);
}
