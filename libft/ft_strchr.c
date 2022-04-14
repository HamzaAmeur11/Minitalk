/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:02:22 by hameur            #+#    #+#             */
/*   Updated: 2021/11/08 18:47:06 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	char	*str;

	str = (char *) s;
	x = 0;
	while (str[x] != 0)
	{
		if (str[x] == (char) c)
			return (str + x);
		else
			x++;
	}
	if (str[x] == 0 && c == 0)
		return (str + x);
	return (NULL);
}
