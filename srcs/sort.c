/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/05 18:28:40 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 16:02:32 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		sortt(t_ls *during, t_ls *last)
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
	if (sduring.st_mtime < slast.st_mtime)
		return (-1);
	else if (sduring.st_mtime > slast.st_mtime)
		return (1);
	else
		return (0);
}

int		sortstrcmp(t_ls *during, t_ls *last)
{
	if (ft_strcmp(during->name, last->name) > 0)
		return (-1);
	else if (ft_strcmp(during->name, last->name) < 0)
		return (1);
	else
		return (0);
}

t_ls	**sort_array(t_ls **array, int (*pf)(t_ls *during, t_ls *last))
{
	int		i;
	t_ls	*tmp;
	int		ret;
	int		done;

	i = 0;
	done = 0;
	while (!done)
	{
		done = 1;
		while (array[++i])
		{
			if ((ret = pf(array[i], array[i - 1])) > 0)
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				done = 0;
			}
			if (ret == -2)
				return (NULL);
		}
		i = 0;
	}
	return (array);
}

t_ls	**rev_array(t_ls **array, t_option *p_option)
{
	int		i;
	int		j;
	t_ls	*tmp;

	i = 0;
	j = 0;
	while (array[i + 1])
		i++;
	while (j < i)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		i--;
		j++;
	}
	return (array);
}

t_ls	**sort_name(t_ls **array_name, t_option *p_option)
{
	if (array_name[1] == NULL)
		return (array_name);
	if ((array_name = sort_array(array_name, &sortstrcmp)) == NULL)
		return (NULL);
	if (p_option->t)
		if ((array_name = sort_array(array_name, &sortt)) == NULL)
			return (NULL);
	if (p_option->r)
		array_name = rev_array(array_name, p_option);
	return (array_name);
}
