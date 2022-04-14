/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:25:45 by hameur            #+#    #+#             */
/*   Updated: 2021/11/15 18:34:04 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	rouller;
	size_t	x;

	len_src = ft_strlen(src);
	len_dst = ft_strlen((const char *) dst);
	rouller = 0;
	x = len_dst;
	if (src[0] == 0)
		return (len_dst);
	if (len_dst >= dstsize)
		return (dstsize + len_src);
	if (len_dst < dstsize)
	{
		while (src[rouller] != 0 && x < dstsize - 1)
			dst[x++] = src[rouller++];
		dst[x] = 0;
		return (len_dst + len_src);
	}
	return (0);
}
