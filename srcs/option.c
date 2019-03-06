/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 18:35:51 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 16:32:09 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_find_option(int i, char **av)
{
	int j;

	j = -1;
	while (av[i][++j])
	{
		if (((((count_char(av[i], '-')) > 2) || (((count_char(av[i], '-')) == 2)
		&& (av[i][2] != ' ' || av[i][2] != '\0'))) ||
		!(str_search(av[i][j], "lRart1mS-"))))
		{
			ft_putstr("./ft_ls: illegal option ");
			ft_putstr("--");
			ft_putchar(av[i][j]);
			ft_putchar('\n');
			ft_putendl("usage: ft_ls [-RlartS1m] [file ...]");
			return (-1);
		}
	}
	return (0);
}

void	find_option_dis(char av, t_option *p_option)
{
	if (av == 'l')
	{
		p_option->l = 1;
		p_option->c = 0;
		p_option->m = 0;
	}
	if (av == '1')
	{
		p_option->l = 0;
		p_option->c = 1;
		p_option->m = 0;
	}
	if (av == 'm')
	{
		p_option->l = 0;
		p_option->c = 0;
		p_option->m = 1;
	}
}

void	find_option_bis(char **av, t_option *p_option, int i)
{
	int		j;

	j = 0;
	while (av[i][j])
	{
		find_option_dis(av[i][j], p_option);
		if (av[i][j] == 'R')
			p_option->er = 1;
		if (av[i][j] == 'a')
			p_option->a = 1;
		if (av[i][j] == 'r')
			p_option->r = 1;
		if (av[i][j] == 't')
			p_option->t = 1;
		if (av[i][j] == 'S')
		{
			p_option->t = 0;
			p_option->os = 1;
		}
		j++;
	}
}

int		find_option_bis_norme(char **av, int i, t_option *p_option, int ac)
{
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
		{
			if ((count_char(av[i], '-') == 1))
			{
				if ((error_find_option(i, av)) == -1)
					return (-1);
				find_option_bis(av, p_option, i);
				if (ft_strstr(av[i], " "))
					break ;
			}
			else if (((count_char(av[i], '-')) >= 2) && (ft_strlen(av[i])) > 2)
			{
				if ((error_find_option(i, av)) == -1)
					return (-1);
			}
			else
				return (i + 1);
		}
		else
			return (i);
	}
	return (i);
}

int		find_option(char **av, int ac, t_option *p_option)
{
	int			i;
	int			ret;

	*(int*)p_option = 0;
	i = 0;
	if (ac == 1)
		return (0);
	ret = find_option_bis_norme(av, i, p_option, ac);
	return (ret);
}
