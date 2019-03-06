/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_bis.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:31:03 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 15:23:51 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_del(char *str, int i, int j)
{
	char	*res;
	int		a;
	int		b;

	res = malloc(sizeof(char) * ft_strlen(str) - i);
	a = 0;
	while (str[i])
	{
		res[a] = str[i];
		i++;
		a++;
	}
	res[a] = '\0';
	b = ft_strlen(str);
	while (j)
	{
		res[b] = '\0';
		b--;
		j--;
	}
	return (res);
}

void		display_long_noa(t_ls *array, t_max *p_max)
{
	if (array->name[0] != '.' || (array->name[0]
		== '.' && array->name[1]
		== '.' && array->name[2]))
	{
		find_pro(array);
		display_space(array, p_max);
		display_date(array);
		ft_putstr(array->name);
		if (array->type_file == 'l')
			display_link(array);
		ft_putchar('\n');
	}
}

void		display_long_a(t_ls *array, t_max *p_max)
{
	find_pro(array);
	display_space(array, p_max);
	display_date(array);
	ft_putstr(array->name);
	if (array->type_file == 'l')
		display_link(array);
	ft_putchar('\n');
}

void		display_link(t_ls *array)
{
	char	link[1000];
	int		i;

	i = readlink(array->path, link, 1000);
	link[i] = '\0';
	ft_putstr(" -> ");
	ft_putstr(link);
}
