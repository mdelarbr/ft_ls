/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_bis.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 16:35:34 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:41:29 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*init_spefile(t_option *p_option, struct dirent *flux, char *path)
{
	t_ls			*p_ls;
	struct stat		buf;
	struct group	*group;
	struct passwd	*user;

	p_ls = malloc(sizeof(t_ls));
	if (lstat(path, &buf) == -1)
	{
		perror(path);
		return (NULL);
	}
	group = getgrgid(buf.st_gid);
	user = getpwuid(buf.st_uid);
	p_ls->type_file = type_file(path);
	p_ls->name = ft_strdup(flux->d_name);
	p_ls->path = ft_strdup(path);
	p_ls->hour_modif = ft_strdup(ctime(&buf.st_mtime));
	p_ls->octets = ft_itoa(buf.st_size);
	if (p_option->l)
		p_ls->p_lsl = init_lsl_spe(p_ls, buf, group, user);
	else
		p_ls->p_lsl = NULL;
	return (p_ls);
}

t_ls	*init_root(t_option *p_option, char *av)
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
	p_ls->path = ft_strdup(av);
	p_ls->hour_modif = ft_strdup(ctime(&buf.st_mtime));
	p_ls->octets = ft_itoa(buf.st_size);
	if (p_option->l)
		p_ls->p_lsl = init_lsl(p_ls, buf, group, user);
	else
		p_ls->p_lsl = NULL;
	return (p_ls);
}

t_ls	*init_folder(t_option *p_option, char *av)
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
