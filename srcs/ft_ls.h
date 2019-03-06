/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 14:52:47 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 17:11:47 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <dirent.h>
# include <grp.h>
# include <errno.h>
# include "../libft/libft.h"
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>

typedef struct	s_lsl
{
	int				protection;
	char			*link;
	int				nb_allocate_bloc;
	char			*team;
	char			*user;
	char			*major;
	char			*minor;
	int				max_major;
	int				max_minor;
	int				max_lnkl;
	int				max_name;
	int				max_group;
	int				max_size;
}				t_lsl;

typedef	struct	s_ls
{
	char			*name;
	char			type_file;
	char			*hour_modif;
	char			*path;
	char			*octets;
	t_lsl			*p_lsl;
}				t_ls;

typedef	struct	s_option
{
	int				l: 1;
	int				er: 1;
	int				a: 1;
	int				r: 1;
	int				t: 1;
	int				c: 1;
	int				m: 1;
	int				os: 1;
}				t_option;

typedef	struct	s_max
{
	int				total;
	int				lnk;
	int				name;
	int				group;
	int				size;
	int				major;
	int				minor;
}				t_max;

/*
** LIBC-----
*/

struct dirent	*readdir(DIR *dir);
int				closedir(DIR *dir);
int				lstat(const char *path, struct stat *buf);
DIR				*opendir(const char *name);
void			perror(const char *s);
char			*strerror(int errnum);
ssize_t			readlink(const char *path, char *buf, size_t bufsiz);

/*
** FT_LS.C-----
*/

void			del_leaks(t_ls *array_name, t_ls **array, t_option *p_option);
void			solver(t_ls *array_name, t_ls **array, t_option *p_option);
int				main(int ac, char **av);

/*
** FOLDER.C-----
*/

void			find_type(char **av, int nb, t_option *p_option);
void			fill_folder(t_ls *array_name, t_option *p_option, int dir);
t_ls			*name_folder(char *av, t_option *p_option);
t_ls			**solve_folder(t_ls *array_name, t_option *p_option);
void			no_folder(t_option *p_option);
t_ls			*name_root(t_option *p_option, char *av);

/*
** FILE.C-----
*/

int				nb_file(char **av, int nb);
int				nb_folder(char **av, int nb);
t_ls			*file(char *av, t_option *p_option);
t_ls			**find_file(char **av, int nb, t_option *p_option);
char			type_file(char *name);

/*
** STRUCT.C-----
*/

char			*init_protection(struct stat *buf);
int				find_path_bis(char *av);
char			*find_path(char *av);
char			*find_path_name(char *av);
char			*ft_strjoinpath(char *base, char *add);
void			struct_del(t_ls **array);

/*
** INIT.C-----
*/

t_ls			*init_link(t_option *p_option, char *path);
t_ls			*init_infolder(t_option *p_option, struct dirent *flux,
		char *path);
t_ls			*init_file(t_option *p_option, char *av);
int				list_actual(char *path);
t_lsl			*init_lsl(t_ls *p_ls, struct stat buf,
		struct group *group, struct passwd *user);
t_lsl			*init_lsl_spe(t_ls *p_ls, struct stat buf,
		struct group *group, struct passwd *user);

/*
** INIT_BIS.C-----
*/

t_ls			*init_spefile(t_option *p_option, struct dirent *flux,
		char *path);
t_ls			*init_root(t_option *p_option, char *av);
t_ls			*init_folder(t_option *p_option, char *av);

/*
** DISPLAY.C-----
*/

void			display_file(t_ls **array, t_option *p_option);
void			display_nameroot(t_option *p_option, t_ls *array_name);
void			display_long_dir(t_ls *array_name, t_ls **array,
		t_option *p_option, int i);
void			display_long_file(t_ls **array,
		t_option *p_option);

/*
** DISPLAY_OPTION.C-----
*/

void			find_display(t_ls *array_name, t_ls **array,
		t_option *p_option, int i);
void			display_folder(t_ls *array_name, t_ls **array,
		t_option *p_option, int dir);
void			display_comma_bis(t_ls *array, t_option *p_option);
void			display_comma(t_ls *array_name, t_ls **array,
		t_option *p_option, int dir);

/*
** DISPLAY_BIS.C-----
*/

void			display_tab(t_ls *array, t_option *p_option);
void			display_long(t_ls *array, t_option *p_option, t_max *p_max);
void			display_link(t_ls *array);
void			display_long_noa(t_ls *array, t_max *p_max);
void			display_long_a(t_ls *array, t_max *p_max);
char			*ft_del(char *str, int i, int j);

/*
** DISPLAY_ACL.C-----
*/

void			display_acl(acl_t acl);
void			get_acl(char *path);

/*
** DISPLAY_LONG.C-----
*/

void			display_space_lnk_user(t_ls *array, t_max *p_max);
void			display_space_min_maj(t_ls *array, t_max *p_max);
void			display_space_size(t_ls *array, t_max *p_max);
void			display_space(t_ls *array, t_max *p_max);
void			display_tab(t_ls *array, t_option *p_option);

/*
** DISPLAY_SPACE.C-----
*/

t_max			*get_lenght_dis(t_ls **array, t_max *p_max, t_option *p_option);
void			get_lenght_disbis(t_ls *array, t_max *p_max,
				t_option *p_option);
void			get_lenght_init(t_ls *array, t_max *p_max);
void			find_pro(t_ls *array);
void			display_date(t_ls *array);

/*
** SORT.C-----
*/

int				sortt(t_ls *during, t_ls *last);
int				sortstrcmp(t_ls *during, t_ls *last);
t_ls			**sort_array(t_ls **array, int (*pf)(t_ls *during, t_ls *last));
t_ls			**rev_array(t_ls **array, t_option *p_option);
t_ls			**sort_name(t_ls **array_name, t_option *p_option);
int				sortsize(t_ls *during, t_ls *last);

/*
** OPTION.C-----
*/

int				error_find_option(int i, char **av);
void			find_option_bis(char **av, t_option *p_option, int i);
int				find_option_bis_norme(char **av, int i, t_option *p_option,
		int ac);
int				find_option(char **av, int ac, t_option *p_option);

#endif
