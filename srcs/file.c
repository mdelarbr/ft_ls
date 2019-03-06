/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 11:27:47 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 15:37:33 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		nb_file(char **av, int nb)
{
	struct stat	buf;
	int			file;
	int			a;

	a = 0;
	file = 0;
	while (av[nb])
	{
		if (lstat(av[nb], &buf) == -1)
			nb++;
		else if (S_ISDIR(buf.st_mode) != 1)
			file++;
		if (lstat(av[nb], &buf) == -1)
			a++;
		else
			nb++;
	}
	return (file);
}

int		nb_folder(char **av, int nb)
{
	struct stat	buf;
	int			file;
	int			a;

	a = 0;
	file = 0;
	while (av[nb])
	{
		if (lstat(av[nb], &buf) == -1)
			nb++;
		else if (S_ISDIR(buf.st_mode) == 1)
			file++;
		if (lstat(av[nb], &buf) == -1)
			a++;
		else
			nb++;
	}
	return (file);
}

t_ls	**find_file(char **av, int nb, t_option *p_option)
{
	t_ls			**array;
	struct stat		buf;
	int				i;

	i = 0;
	array = malloc(sizeof(t_ls*) * (nb_file(av, nb) + 1));
	while (av[nb])
	{
		if (lstat(av[nb], &buf) == -1)
		{
			ft_putstr("./ft_ls: ");
			perror(av[nb]);
		}
		else if (S_ISDIR(buf.st_mode) != 1)
		{
			array[i] = init_file(p_option, av[nb]);
			i++;
		}
		nb++;
	}
	array[i] = NULL;
	return (array);
}

char	type_file(char *name)
{
	struct stat		buf;
	struct stat		bufl;
	char			res;

	res = '\0';
	if ((lstat(name, &buf)) == -1)
		return ('\0');
	if ((lstat(name, &bufl)) == -1)
		return ('\0');
	if (S_ISLNK(bufl.st_mode) == 1)
		res = 'l';
	else if (S_ISREG(buf.st_mode) == 1)
		res = '-';
	else if (S_ISDIR(buf.st_mode) == 1)
		res = 'd';
	else if (S_ISCHR(buf.st_mode) == 1)
		res = 'c';
	else if (S_ISBLK(buf.st_mode) == 1)
		res = 'b';
	else if (S_ISFIFO(buf.st_mode) == 1)
		res = 'p';
	else
		res = 's';
	return (res);
}
