/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:39:12 by hameur            #+#    #+#             */
/*   Updated: 2021/11/20 21:43:59 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_digit(int xb)
{
	int			count;
	long int	x;

	x = (long int)xb;
	count = 0;
	if (x < 0)
		x = -x;
	while (x > 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}

static char	*positive_itoa(int n)
{
	char	*p;
	int		x;

	if (n == 0)
	{
		p = (char *)malloc(2 * sizeof (char));
		p[0] = '0';
		p[1] = 0;
		return (p);
	}
	x = nbr_digit(n);
	p = (char *)malloc((x + 1) * sizeof (char));
	if (!p)
		return (NULL);
	p[x--] = 0;
	while (x >= 0)
	{
		p[x--] = ((n % 10) + 48);
		n = n / 10;
	}
	return (p);
}

static char	*negative_itoa(int nb)
{
	char		*p;
	int			x;
	long int	n;

	n = (long int)nb;
	x = nbr_digit(-n);
	n = -n;
	p = (char *)malloc((x + 2) * sizeof (char));
	if (!p)
		return (NULL);
	p[0] = '-';
	p[x + 1] = 0;
	while (x > 0)
	{
		p[x--] = ((n % 10) + 48);
		n = n / 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;

	if (n < 0)
		p = negative_itoa(n);
	if (n >= 0)
		p = positive_itoa(n);
	if (!p)
		return (NULL);
	return (p);
}
