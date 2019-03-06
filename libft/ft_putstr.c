/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:13:51 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 19:25:20 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int index;

	index = 0;
	if (!(s))
		return ;
	while (s[index] != '\0')
	{
		ft_putchar(s[index]);
		index++;
	}
}
