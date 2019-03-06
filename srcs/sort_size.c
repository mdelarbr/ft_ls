/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort_size.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 13:22:27 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 13:23:15 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		sortsize(t_ls *during, t_ls *last)
{
	int			i;
	struct stat	sduring;
	struct stat	slast;

	i = 0;
	if (lstat(during->path, &sduring) == -1)
	{
		perror("during");
		return (-2);
	}
	if (lstat(last->path, &slast) == -1)
	{
		perror("last");
		return (-2);
	}
	if (sduring.st_size < slast.st_size)
		return (-1);
	else if (sduring.st_size > slast.st_size)
		return (1);
	else
		return (0);
}
