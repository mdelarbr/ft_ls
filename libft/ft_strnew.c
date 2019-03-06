/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:39:08 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 17:21:42 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr_new;
	size_t	i;

	if (!(ptr_new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (size--)
	{
		ptr_new[i++] = '\0';
	}
	ptr_new[i] = '\0';
	return (ptr_new);
}
