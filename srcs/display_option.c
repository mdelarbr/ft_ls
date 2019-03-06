/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_option.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 15:33:30 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 16:04:19 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	find_display(t_ls *array_name, t_ls **array, t_option *p_option, int i)
{
	if (p_option->l)
	{
		if (array_name != NULL)
			display_long_dir(array_name, array, p_option, i);
		else
			display_long_file(array, p_option);
	}
	else if (p_option->m)
		display_comma(array_name, array, p_option, i);
	else
		display_folder(array_name, array, p_option, i);
}

void	display_folder(t_ls *array_name, t_ls **array, t_option *p_option,
		int dir)
{
	int		i;

	i = 0;
	if (dir > 1)
	{
		ft_putchar('\n');
		if (!p_option->er)
			ft_putstr(array_name->name);
		else
			ft_putstr(array_name->path);
		ft_putendl(":");
	}
	while (array[i])
	{
		display_tab(array[i], p_option);
		i++;
	}
	ft_putchar('\n');
}

void	display_comma_bis(t_ls *array, t_option *p_option)
{
	if (p_option->a == 0)
	{
		if (array->name[0] != '.' || (array->name[0] != '.'
			&& array->name[1] != '.'))
		{
			ft_putstr(array->name);
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	else
	{
		ft_putstr(array->name);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	display_comma(t_ls *array_name, t_ls **array, t_option *p_option,
		int dir)
{
	int		i;

	i = -1;
	if (dir > 1)
	{
		ft_putchar('\n');
		if (!p_option->er)
			ft_putstr(array_name->name);
		else
			ft_putstr(array_name->path);
		ft_putendl(":");
	}
	while (array[++i])
		display_comma_bis(array[i], p_option);
	ft_putchar('\n');
}
