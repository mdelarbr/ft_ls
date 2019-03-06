/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 14:53:49 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 15:55:49 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_leaks_l(t_ls *array)
{
	free(array->p_lsl->link);
	free(array->p_lsl->major);
	free(array->p_lsl->minor);
	free(array->p_lsl->user);
	free(array->p_lsl->team);
	free(array->p_lsl);
}

void	del_leaks_name(t_ls *array_name)
{
	free(array_name->name);
	free(array_name->hour_modif);
	free(array_name->octets);
	free(array_name->path);
	free(array_name);
}

void	del_leaks(t_ls *array_name, t_ls **array, t_option *p_option)
{
	int		i;

	i = 0;
	if (array_name)
	{
		if (p_option->l)
			del_leaks_l(array_name);
		del_leaks_name(array_name);
	}
	if (array)
	{
		while (array[i])
		{
			if (p_option->l)
				del_leaks_l(array[i]);
			free(array[i]->name);
			free(array[i]->hour_modif);
			free(array[i]->octets);
			free(array[i]->path);
			free(array[i]);
			i++;
		}
	}
	free(array);
}

void	solver(t_ls *array_name, t_ls **array, t_option *p_option)
{
	t_ls	**tmp;

	if (array[1] != NULL)
	{
		if ((array = sort_array(array, &sortstrcmp)) == NULL)
			return ;
		if (p_option->t)
			if ((array = sort_array(array, &sortt)) == NULL)
				return ;
		if (p_option->os)
			if ((array = sort_array(array, &sortsize)) == NULL)
				return ;
		if (p_option->r)
			array = rev_array(array, p_option);
	}
	find_display(array_name, array, p_option, 0);
}

int		main(int ac, char **av)
{
	t_ls		**array;
	t_option	p_option;
	int			nb;

	nb = find_option(av, ac, &p_option);
	if (nb == -1)
		return (0);
	if (nb > 0)
	{
		if ((array = find_file(av, nb, &p_option)) && array[0])
			solver(NULL, array, &p_option);
		del_leaks(NULL, array, &p_option);
	}
	if (nb == 0 || (nb == ac))
		no_folder(&p_option);
	else
		find_type(av, nb, &p_option);
	return (1);
}
