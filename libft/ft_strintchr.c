/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strintchr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/03 16:39:47 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 16:45:41 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strintchr(char *str, char to_find)
{
	int i;
	int find;

	i = 0;
	find = 0;
	if (to_find == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			find = i;
		i++;
	}
	return (find);
}
