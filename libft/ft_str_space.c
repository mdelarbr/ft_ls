/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_space.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 11:15:15 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 11:18:07 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_space(const char *s, size_t i)
{
	if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		return (1);
	return (0);
}
