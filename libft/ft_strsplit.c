/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:50:23 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 11:55:19 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	cnt;

	i = 0;
	if (s == '\0')
		return (NULL);
	cnt = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (NULL);
	while (i < cnt)
	{
		tab[i] = ft_get_word(s, c, i + 1);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
