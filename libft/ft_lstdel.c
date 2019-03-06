/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 07:49:20 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 08:24:52 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxt_lst;

	lst = *alst;
	while (lst)
	{
		nxt_lst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxt_lst;
	}
	*alst = NULL;
}
