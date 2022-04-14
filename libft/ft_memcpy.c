/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:24:13 by hameur            #+#    #+#             */
/*   Updated: 2021/12/06 13:13:01 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*t_dst;
	char	*t_src;
	size_t	x;

	t_dst = (char *) dst;
	t_src = (char *) src;
	x = 0;
	if (!src && !dst)
		return (NULL);
	while (x < n)
	{
		t_dst[x] = t_src[x];
		x++;
	}
	return (t_dst);
}
