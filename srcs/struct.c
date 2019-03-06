/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 13:14:10 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 12:19:15 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		find_path_bis(char *av)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (av[i] == '/' && av[i + 1] != '\0')
			count = i;
		i++;
	}
	return (count);
}

char	*find_path(char *av)
{
	int		i;
	int		a;
	char	*path;

	if (!(i = find_path_bis(av)))
		return (".");
	a = 0;
	path = malloc(sizeof(char) * i + 2);
	while (av[i])
	{
		path[a] = av[a];
		i--;
		a++;
	}
	path[a] = '\0';
	return (path);
}

char	*find_path_name(char *av)
{
	char	*path;
	int		i;
	int		a;
	char	*res;

	i = 0;
	a = 0;
	path = find_path(av);
	if (ft_strlen(path) > 2)
		while (path[i])
			i++;
	if ((path[0] != '.' && path[1] != 0) || (path[0] == '.' && path[1] != 0))
		free(path);
	res = malloc(sizeof(char) * (ft_strlen(av) - i) + 1);
	i -= 1;
	while (av[++i])
	{
		res[a] = av[i];
		a++;
	}
	if (res[a - 1] == '/')
		res[a - 1] = '\0';
	else
		res[a] = '\0';
	return (res);
}

char	*ft_strjoinpath(char *base, char *add)
{
	char	*path;
	char	*tmp;

	if (base[0] == '\0')
	{
		path = malloc(sizeof(char) * ft_strlen(add) + 1);
		path = ft_strcpy(path, add);
		return (path);
	}
	tmp = ft_strjoin(base, "/");
	base = tmp;
	path = ft_strjoin(base, add);
	free(tmp);
	return (path);
}

void	struct_del(t_ls **array)
{
	int		i;

	i = -1;
	if (array == NULL)
		return ;
	while (array[++i])
	{
		free(array[i]->name);
		free(array[i]->hour_modif);
		free(array[i]->path);
		free(array[i]->p_lsl);
		free(array[i]);
	}
}
