/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_long.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 15:14:09 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 16:04:24 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_space_lnk_user(t_ls *array, t_max *p_max)
{
	int		n;

	n = array->p_lsl->max_lnkl;
	while (n < (p_max->lnk + 1))
	{
		ft_putchar(' ');
		n++;
	}
	ft_putstr(array->p_lsl->link);
	ft_putchar(' ');
	ft_putstr(array->p_lsl->user);
	n = array->p_lsl->max_name;
	while (n < (p_max->name + 1))
	{
		ft_putchar(' ');
		n++;
	}
	n = array->p_lsl->max_group;
	ft_putstr(array->p_lsl->team);
	while (n < (p_max->group + 1))
	{
		ft_putchar(' ');
		n++;
	}
}

void		display_space_min_maj(t_ls *array, t_max *p_max)
{
	int		n;

	n = array->p_lsl->max_major;
	while (n < (p_max->major + 2))
	{
		ft_putchar(' ');
		n++;
	}
	ft_putstr(array->p_lsl->major);
	ft_putchar(',');
	n = array->p_lsl->max_minor;
	while (n < (p_max->minor + 1))
	{
		ft_putchar(' ');
		n++;
	}
	ft_putstr(array->p_lsl->minor);
}

void		display_space_size(t_ls *array, t_max *p_max)
{
	int	n;

	n = array->p_lsl->max_size;
	while (n < (p_max->size + 2))
	{
		ft_putchar(' ');
		n++;
	}
	ft_putstr(array->octets);
}

void		display_space(t_ls *array, t_max *p_max)
{
	get_acl(array->path);
	display_space_lnk_user(array, p_max);
	if (array->type_file == 'c' || array->type_file == 'b')
		display_space_min_maj(array, p_max);
	else
		display_space_size(array, p_max);
}

void		display_tab(t_ls *array, t_option *p_option)
{
	if (!p_option->a)
	{
		if (array->name[0] != '.' || (array->name[0]
		== '.' && array->name[1]
		== '.' && array->name[2]))
		{
			if (!p_option->c)
			{
				ft_putstr(array->name);
				ft_putchar('\t');
			}
			else
				ft_putendl(array->name);
		}
	}
	else
	{
		if (!p_option->c)
		{
			ft_putstr(array->name);
			ft_putchar('\t');
		}
		else
			ft_putendl(array->name);
	}
}
