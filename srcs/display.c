/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/10 21:24:05 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 16:48:18 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_file(t_ls **array, t_option *p_option)
{
	int		i;

	i = 0;
	while (array[i])
	{
		if (!p_option->a)
		{
			if (array[i]->name[0] != '.' || (array[i]->name[0] != '.'
				&& array[i]->name[1] != '.'))
				ft_putendl(array[i]->name);
		}
		else
			ft_putendl(array[i]->name);
		i++;
	}
}

void	display_nameroot(t_option *p_option, t_ls *array_name)
{
	ft_putchar('\n');
	if (!p_option->er)
		ft_putstr(array_name->name);
	else
		ft_putstr(array_name->path);
	ft_putendl(":");
}

void	display_long_dir(t_ls *array_name, t_ls **array, t_option *p_option,
		int dir)
{
	int		i;
	t_max	*p_max;

	i = -1;
	p_max = malloc(sizeof(t_max));
	if (dir > 1)
		display_nameroot(p_option, array_name);
	i = -1;
	p_max = get_lenght_dis(array, p_max, p_option);
	ft_putstr("total ");
	ft_putnbr(p_max->total);
	ft_putchar('\n');
	while (array[++i])
	{
		if (!p_option->a)
			display_long_noa(array[i], p_max);
		else
			display_long_a(array[i], p_max);
	}
	free(p_max);
}

void	display_long_file(t_ls **array, t_option *p_option)
{
	int		i;
	t_max	*p_max;

	i = 0;
	p_max = malloc(sizeof(t_max));
	p_max = get_lenght_dis(array, p_max, p_option);
	while (array[i])
	{
		if (!p_option->a)
			display_long_noa(array[i], p_max);
		else
			display_long_a(array[i], p_max);
		i++;
	}
	free(p_max);
}
