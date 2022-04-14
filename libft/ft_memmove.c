/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:36:23 by hameur            #+#    #+#             */
/*   Updated: 2021/12/06 13:13:19 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t_dst;
	char	*t_src;

	t_dst = (char *) dst;
	t_src = (char *) src;
	if (src < dst)
	{
		while (len--)
			t_dst[len] = t_src[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
