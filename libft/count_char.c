/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   count_char.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 14:35:26 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 20:02:40 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		count_char(char *src, char find)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == find)
			nb++;
		i++;
	}
	return (nb);
}
