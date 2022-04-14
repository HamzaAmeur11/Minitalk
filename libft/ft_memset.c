/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:50:10 by hameur            #+#    #+#             */
/*   Updated: 2021/11/15 17:07:20 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			x;
	unsigned char	*h;

	x = 0;
	h = (unsigned char *)b;
	while (x < len)
	{
		h[x] = (unsigned char) c;
		x++;
	}
	return (h);
}
