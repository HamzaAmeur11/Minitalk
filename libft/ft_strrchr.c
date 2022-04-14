/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:14:58 by hameur            #+#    #+#             */
/*   Updated: 2021/11/15 18:51:56 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*str;

	str = (char *) s;
	x = (int) ft_strlen(s);
	if (c == 0)
		return (str + x);
	while (x >= 0)
	{
		if (str[x] == (char) c)
			return (str + x);
		else
			x--;
	}
	return (NULL);
}
