/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 11:12:02 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 16:44:33 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*init_infolder(t_option *p_option, struct dirent *flux, char *path)
{
	struct stat		buf;
	t_ls			*p_ls;
	struct group	*group;
	struct passwd	*user;

	p_ls = malloc(sizeof(t_ls));
	p_ls->path = ft_strdup(path);
	if (lstat(p_ls->path, &buf) == -1)
	{
		perror(p_ls->path);
		return (NULL);
	}
	group = getgrgid(buf.st_gid);
	user = getpwuid(buf.st_uid);
	p_ls->name = ft_strdup(flux->d_name);
	p_ls->type_file = type_file(p_ls->path);
	p_ls->hour_modif = ft_strdup(ctime(&buf.st_mtime));
	p_ls->octets = ft_itoa(buf.st_size);
	if (p_option->l)
		p_ls->p_lsl = init_lsl(p_ls, buf, group, user);
	else
		p_ls->p_lsl = NULL;
	return (p_ls);
}

t_ls	*init_file(t_option *p_option, char *av)
{
	struct stat		buf;
	t_ls			*p_ls;
	struct group	*group;
	struct passwd	*user;

	p_ls = malloc(sizeof(t_ls));
	if (lstat(av, &buf) == -1)
	{
		perror(av);
		return (NULL);
	}
	group = getgrgid(buf.st_gid);
	user = getpwuid(buf.st_uid);
	p_ls->name = ft_strdup(av);
	p_ls->type_file = type_file(av);
	p_ls->hour_modif = ft_strdup(ctime(&buf.st_mtime));
	p_ls->octets = ft_itoa(buf.st_size);
	p_ls->path = ft_strdup(av);
	if (p_option->l)
		p_ls->p_lsl = init_lsl(p_ls, buf, group, user);
	else
		p_ls->p_lsl = NULL;
	return (p_ls);
}

int		list_actual(char *path)
{
	int				i;
	DIR				*id;
	struct dirent	*flux;

	i = 0;
	if ((id = opendir(path)) == NULL)
	{
		perror(path);
		return (-1);
	}
	while ((flux = readdir(id)) != NULL)
		i++;
	closedir(id);
	return (i);
}

t_lsl	*init_lsl(t_ls *p_ls, struct stat buf,
		struct group *group, struct passwd *user)
{
	p_ls->p_lsl = malloc(sizeof(t_lsl));
	p_ls->p_lsl->link = ft_itoa(buf.st_nlink);
	p_ls->p_lsl->nb_allocate_bloc = buf.st_blocks;
	p_ls->p_lsl->protection = buf.st_mode;
	p_ls->p_lsl->user = ft_strdup(user->pw_name);
	p_ls->p_lsl->team = ft_strdup(group->gr_name);
	p_ls->p_lsl->major = ft_itoa(0);
	p_ls->p_lsl->minor = ft_itoa(0);
	return (p_ls->p_lsl);
}

t_lsl	*init_lsl_spe(t_ls *p_ls, struct stat buf,
		struct group *group, struct passwd *user)
{
	p_ls->p_lsl = malloc(sizeof(t_lsl));
	p_ls->p_lsl->link = ft_itoa(buf.st_nlink);
	p_ls->p_lsl->nb_allocate_bloc = buf.st_blocks;
	p_ls->p_lsl->protection = buf.st_mode;
	p_ls->p_lsl->user = ft_strdup(user->pw_name);
	p_ls->p_lsl->team = ft_strdup(group->gr_name);
	p_ls->p_lsl->major = ft_itoa(major(buf.st_rdev));
	p_ls->p_lsl->minor = ft_itoa(minor(buf.st_rdev));
	return (p_ls->p_lsl);
}
