/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   folder.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 13:17:53 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/26 15:36:31 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*name_folder_array(char *tmp, char *av, DIR *id, t_option *p_option)
{
	t_ls			*array_name;
	struct dirent	*flux;

	while ((flux = readdir(id)) != NULL)
	{
		if (ft_strcmp(flux->d_name, (tmp = find_path_name(av))) == 0)
		{
			closedir(id);
			free(tmp);
			array_name = init_folder(p_option, av);
			return (array_name);
		}
		free(tmp);
	}
	closedir(id);
	return (NULL);
}

t_ls	*name_folder(char *av, t_option *p_option)
{
	t_ls			*array_name;
	DIR				*id;
	char			*tmp;

	tmp = find_path(av);
	if (ft_strcmp(tmp, ".") == 0)
		return (array_name = name_root(p_option, av));
	if ((id = opendir(tmp)) == NULL)
	{
		perror("name folder: ");
		free(tmp);
		return (NULL);
	}
	if ((tmp[0] != '.' && tmp[1] != 0) || (tmp[0] == '.' && tmp[1] != 0))
		free(tmp);
	if ((array_name = name_folder_array(tmp, av, id, p_option)) != NULL)
		return (array_name);
	return (NULL);
}

t_ls	*solve_type(t_ls *array, struct dirent *flux, t_ls *array_name,
		t_option *p_option)
{
	char			*tmp;
	char			c;

	tmp = ft_strjoinpath(array_name->path, flux->d_name);
	c = type_file(tmp);
	if (c == '\0')
		return (NULL);
	if (c == '-' || c == 'p' || c == 's' || c == 'd' || c == 'l')
		array = init_infolder(p_option, flux, tmp);
	if (c == 'c' || c == 'b')
		array = init_spefile(p_option, flux, tmp);
	free(tmp);
	return (array);
}

t_ls	**solve_folder(t_ls *array_name, t_option *p_option)
{
	struct dirent	*flux;
	t_ls			**array;
	DIR				*id;
	int				i;

	i = 0;
	if (!(array = malloc(sizeof(t_ls) * list_actual(array_name->path) + 1)))
		return (NULL);
	if (((id = opendir(array_name->path))) == NULL)
	{
		perror(array_name->path);
		return (NULL);
	}
	while ((flux = readdir(id)) != NULL)
	{
		array[i] = solve_type(array[i], flux, array_name, p_option);
		i++;
	}
	array[i] = NULL;
	closedir(id);
	return (array);
}

void	fill_folder(t_ls *array_name, t_option *p_option, int dir)
{
	t_ls	**array;
	int		i;

	i = -1;
	if (!(array = solve_folder(array_name, p_option)))
	{
		del_leaks(NULL, array, p_option);
		return ;
	}
	if (array[1] != NULL)
		array = sort_name(array, p_option);
	find_display(array_name, array, p_option, dir);
	if (p_option->er)
	{
		while (array[++i])
		{
			if (array[i]->type_file == 'd' && (array[i]->name[0]
			!= '.' && array[i]->name[1] != '.'))
				fill_folder(array[i], p_option, 2);
		}
	}
	del_leaks(NULL, array, p_option);
}
