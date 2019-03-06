/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   folder_name.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 10:13:45 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 15:43:57 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*name_root(t_option *p_option, char *av)
{
	t_ls			*array_name;

	array_name = init_root(p_option, av);
	return (array_name);
}

void	find_name(int i, t_ls **array_name, int dir, t_option *p_option)
{
	array_name[i] = NULL;
	dir += i;
	array_name = sort_name(array_name, p_option);
	i = -1;
	while (array_name[++i])
		fill_folder(array_name[i], p_option, dir);
}

void	find_type(char **av, int nb, t_option *p_option)
{
	t_ls			**array_name;
	int				dir;
	int				i;

	i = 0;
	dir = 0;
	array_name = malloc(sizeof(t_ls*) * (nb_folder(av, nb) + 1));
	while (av[nb])
	{
		dir += (type_file(av[nb]) == '-');
		if (type_file(av[nb]) == 'd')
			if (!(array_name[i++] = name_folder(av[nb], p_option)))
			{
				del_leaks(NULL, array_name, p_option);
				return ;
			}
		nb++;
	}
	if (!i)
	{
		free(array_name);
		return ;
	}
	find_name(i, array_name, dir, p_option);
	del_leaks(NULL, array_name, p_option);
}

void	no_folder_rec(t_ls **array, t_option *p_option)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (array[i]->type_file == 'd' && (array[i]->name[0]
		!= '.' && array[i]->name[1] != '.'))
			fill_folder(array[i], p_option, 2);
		i++;
	}
}

void	no_folder(t_option *p_option)
{
	int				i;
	DIR				*id;
	t_ls			**array;
	t_ls			*array_name;
	struct dirent	*flux;

	i = -1;
	if (!(array = malloc(sizeof(t_ls) * (list_actual(".")))))
		return ;
	if ((id = opendir(".")) == NULL)
	{
		perror("no_folder");
		return ;
	}
	while ((flux = readdir(id)) != NULL)
		array[++i] = init_folder(p_option, flux->d_name);
	closedir(id);
	array[++i] = NULL;
	solver((array_name = name_folder(".", p_option)), array, p_option);
	i = -1;
	if (p_option->er)
		no_folder_rec(array = sort_name(array, p_option), p_option);
	del_leaks(array_name, array, p_option);
}
