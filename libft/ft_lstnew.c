/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 06:01:13 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 06:42:21 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		list->content = ft_memcpy(ft_memalloc(content_size),
			content, content_size);
		list->content_size = content_size;
		list->next = NULL;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	return (list);
}
