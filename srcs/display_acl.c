/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_acl.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 13:55:53 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 19:08:35 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_acl(acl_t acl)
{
	if (acl != NULL)
		ft_putstr("+");
	else
		ft_putstr(" ");
}

void		get_acl(char *path)
{
	acl_t			acl;
	acl_entry_t		dummy;
	ssize_t			ret;
	char			str[1000];

	ret = listxattr(path, str, 1000, XATTR_NOFOLLOW);
	if (ret > 0)
		ft_putchar('@');
	else if (ret == 0)
	{
		acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
		if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
		{
			acl_free(acl);
			acl = NULL;
		}
		display_acl(acl);
		free(acl);
	}
	else
		ft_putstr(" ");
}
