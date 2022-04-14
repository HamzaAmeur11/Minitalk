/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:32:04 by hameur            #+#    #+#             */
/*   Updated: 2021/11/18 18:15:13 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	i;
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	else if ((size_t)ft_strlen (s + start) < len)
		p = (char *)malloc(ft_strlen (s + start) + 1);
	else
		p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[start] != 0 && i < len)
		p[i++] = s[start++];
	p[i] = 0;
	return (p);
}
