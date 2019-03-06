/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:49:33 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 11:29:42 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	first;
	size_t	last;
	size_t	i;
	char	*tab;

	first = 0;
	i = 0;
	if (!(s))
		return (NULL);
	if (s[i] == '\0')
		return (ft_strnew(1));
	last = ft_strlen(s) - 1;
	while ((ft_str_space(s, first) == 1 && s[first]))
		first++;
	while (ft_str_space(s, last) && last > first)
		last--;
	if (!(tab = (char *)malloc(sizeof(char) * (last - first + 2))))
		return (NULL);
	while (first <= last)
	{
		tab[i++] = s[first];
		first++;
	}
	tab[i] = '\0';
	return (tab);
}
