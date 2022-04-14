/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:24:32 by hameur            #+#    #+#             */
/*   Updated: 2021/12/08 23:59:35 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	len_s1 = ft_strlen((const char *)s1);
	len_s2 = ft_strlen((const char *)s2);
	p = (char *)malloc(len_s1 + len_s2 + 1);
	if (p == 0)
		return (NULL);
	ft_strlcpy(p, (const char *)s1, (size_t)len_s1 + 1);
	ft_strlcat(p, (const char *)s2, (size_t)len_s1 + len_s2 + 1);
	return (p);
}
