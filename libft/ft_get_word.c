/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_word.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 11:52:23 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 12:03:01 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_word(char const *s, char c, int i1)
{
	int		i;
	int		cnt;
	int		temp;
	char	*wrd;

	i = 0;
	while (i1 > 0 && s[i])
	{
		cnt = 0;
		while (s[i] == c && s[i])
			i++;
		temp = i;
		while (s[i++] != c && s[i])
			cnt++;
		i1--;
	}
	if (!(wrd = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	cnt = temp;
	i = 0;
	while (s[cnt] != c && s[cnt])
		wrd[i++] = s[cnt++];
	wrd[i] = 0;
	return (wrd);
}
