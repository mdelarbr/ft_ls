/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_search.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 14:13:06 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 17:33:18 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		str_search(char str, char *res)
{
	int i;
	int	same;

	same = 0;
	i = -1;
	while (res[++i])
		if (res[i] == str)
			same = 1;
	if (same == 1)
		return (1);
	else
		return (0);
}
