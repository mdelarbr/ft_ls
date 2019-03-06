/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:39:41 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 15:37:45 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;

	i = 0;
	if (src > dest)
		dest = ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}
