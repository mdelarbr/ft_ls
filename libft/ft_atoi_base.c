/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 20:54:06 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 10:47:26 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	isvalid(char c, int base)
{
	char	array[17];
	char	array1[17];

	ft_strcpy(array, "0123456789abcdef");
	ft_strcpy(array1, "0123456789ABCDEF");
	while (base--)
		if (array[base] == c || array1[base] == c)
			return (1);
	return (0);
}

int	value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int a;
	int neg;

	neg = 1;
	i = 0;
	a = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (isvalid(*str, str_base))
		a = a * str_base + value_of(*str++);
	return (a * neg);
}
