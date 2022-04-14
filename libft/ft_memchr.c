/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:28:55 by hameur            #+#    #+#             */
/*   Updated: 2021/12/06 13:12:40 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*str;

	str = (unsigned char *) s;
	x = 0;
	if (n == 0)
		return (NULL);
	while (x < n)
	{
		if (str[x] == (unsigned char) c)
			return (str + x);
		x++;
	}
	return (NULL);
}
