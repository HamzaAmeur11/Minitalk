/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:09:04 by hameur            #+#    #+#             */
/*   Updated: 2021/12/04 14:12:19 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*p;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *) s1);
	i = 0;
	j = ft_strlen((const char *)s1);
	while (ft_strchr((const char *)set, (int)s1[i]))
		i++;
	while (ft_strchr((const char *)set, (int )s1[j - 1]) && i < j)
		j--;
	if (j - i < 0)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!p)
		return (NULL);
	ft_strlcpy(p, (s1 + i), (j - i + 1));
	return (p);
}
