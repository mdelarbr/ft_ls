/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mdelarbr <mdelarbr@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 09:57:38 by mdelarbr     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:34:41 by mdelarbr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_isneg(int *bol, int *n)
{
	if (*n < 0)
	{
		*bol = 1;
		*n *= -1;
	}
	else
		*bol = 0;
}

char			*ft_itoa(int n)
{
	int		x;
	int		len;
	char	*array;
	int		bol;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	x = n;
	len = 2;
	while (x /= 10)
		len++;
	ft_isneg(&bol, &n);
	len += bol;
	if (!(array = (char*)malloc(sizeof(char) * len)))
		return (0);
	array[--len] = '\0';
	while (len--)
	{
		array[len] = n % 10 + '0';
		n = n / 10;
	}
	if (bol)
		array[0] = '-';
	return (array);
}
