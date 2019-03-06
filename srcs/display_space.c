/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_space.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 15:19:59 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:09:53 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		find_pro(t_ls *array)
{
	char	res[11];
	int		nb;

	res[10] = '\0';
	nb = array->p_lsl->protection;
	res[0] = array->type_file;
	res[1] = (nb & S_IRUSR) ? 'r' : '-';
	res[2] = (nb & S_IWUSR) ? 'w' : '-';
	res[3] = (nb & S_IXUSR) ? 'x' : '-';
	res[4] = (nb & S_IRGRP) ? 'r' : '-';
	res[5] = (nb & S_IWGRP) ? 'w' : '-';
	res[6] = (nb & S_IXGRP) ? 'x' : '-';
	res[7] = (nb & S_IROTH) ? 'r' : '-';
	res[8] = (nb & S_IWOTH) ? 'w' : '-';
	res[9] = (nb & S_IXOTH) ? 'x' : '-';
	if (nb & S_ISUID)
		res[3] = (nb & S_IXUSR) ? 's' : 'S';
	if (nb & S_ISGID)
		res[6] = (nb & S_IXGRP) ? 's' : 'l';
	if (nb & S_ISVTX)
		res[9] = (nb & S_IXOTH) ? 't' : 'T';
	ft_putstr(res);
}

void		get_lenght_init(t_ls *array, t_max *p_max)
{
	if (array->type_file == 'c' || array->type_file == 'b')
	{
		if (array->p_lsl->max_major > p_max->major)
			p_max->major = array->p_lsl->max_major;
		if (array->p_lsl->max_minor > p_max->minor)
			p_max->minor = array->p_lsl->max_minor;
	}
	if (array->p_lsl->max_lnkl > p_max->lnk)
		p_max->lnk = array->p_lsl->max_lnkl;
	if (array->p_lsl->max_name > p_max->name)
		p_max->name = array->p_lsl->max_name;
	if (array->p_lsl->max_group > p_max->group)
		p_max->group = array->p_lsl->max_group;
	if (array->p_lsl->max_size > p_max->size)
		p_max->size = array->p_lsl->max_size;
}

void		get_lenght_disbis(t_ls *array, t_max *p_max, t_option *p_option)
{
	if (array->type_file == 'c' || array->type_file == 'b')
	{
		array->p_lsl->max_major = ft_strlen(array->p_lsl->major);
		array->p_lsl->max_minor = ft_strlen(array->p_lsl->minor);
	}
	array->p_lsl->max_lnkl = ft_strlen(array->p_lsl->link);
	array->p_lsl->max_name = ft_strlen(array->p_lsl->user);
	array->p_lsl->max_group = ft_strlen(array->p_lsl->team);
	array->p_lsl->max_size = ft_strlen(array->octets);
	if (!p_option->a && (array->name[0] != '.' || (array->name[0] != '.'
				&& array->name[1] != '.')))
		p_max->total += array->p_lsl->nb_allocate_bloc;
	if (p_option->a)
		p_max->total += array->p_lsl->nb_allocate_bloc;
}

t_max		*get_lenght_dis(t_ls **array, t_max *p_max, t_option *p_option)
{
	int		i;

	i = 0;
	p_max->total = 0;
	p_max->lnk = 0;
	p_max->name = 0;
	p_max->group = 0;
	p_max->size = 0;
	p_max->major = 0;
	p_max->minor = 0;
	while (array[i])
	{
		get_lenght_disbis(array[i], p_max, p_option);
		i++;
	}
	i = 0;
	while (array[i])
	{
		get_lenght_init(array[i], p_max);
		i++;
	}
	return (p_max);
}

void		display_date(t_ls *array)
{
	char		*year;
	char		*tmp;
	int			a;
	struct stat	buf;
	char		*res;

	a = 3;
	stat(array->path, &buf);
	if (((time(0) - buf.st_mtime) > 15768000) || ((time(0) - buf.st_mtime) < 0))
	{
		year = (ft_strsub((ctime(&buf.st_mtime)), 4, 7));
		tmp = (ft_strsub((ctime(&buf.st_mtime)), 19, 5));
		res = ft_strjoin(year, tmp);
		free(year);
		free(tmp);
		ft_putchar(' ');
	}
	else
		res = ft_del(array->hour_modif, 3, 13);
	ft_putstr(res);
	ft_putchar(' ');
	free(res);
}
