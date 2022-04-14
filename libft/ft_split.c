/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:26:05 by hameur            #+#    #+#             */
/*   Updated: 2021/12/06 13:13:28 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_mots(char const *s, char c)
{
	int	i;
	int	nbr_mots;

	i = 0;
	nbr_mots = 0;
	if (s[0] != c && s[0])
		nbr_mots++;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != 0)
			{
				nbr_mots++;
				i++;
			}
			else
				i++;
		}
		else
			i++;
	}
	return (nbr_mots);
}

static int	len_chaque_mot(const char *s, char c, int index)
{
	int	count;

	count = 0;
	while (s[index] == c)
		index++;
	while (s[index] != '\0' && s[index] != c)
	{
		index++;
		count++;
	}
	return (count);
}

static char	**ft_free(char **copy, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		free(copy);
		return (NULL);
	}
	while (i < j)
	{
		free (copy[i]);
		i++;
	}
	free (copy);
	return (NULL);
}

static char	**ft_remplissage(char const *s, char **copy, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < nbr_mots(s, c))
	{
		copy[j] = (char *)malloc(sizeof(char) * (len_chaque_mot(s, c, i) + 1));
		if (!(copy[j]))
			return (ft_free(copy, j));
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			copy[j][k++] = s[i++];
		copy[j][k] = '\0';
		j++;
	}
	copy[j] = NULL;
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**copy;

	if (!s)
		return (NULL);
	if (!*s)
	{
		copy = (char **)malloc (sizeof (char *) * 1);
		if (!copy)
			return (NULL);
		copy[0] = NULL;
		return (copy);
	}
	copy = (char **)malloc(sizeof(char *) * (nbr_mots(s, c) + 1));
	if (!copy)
		return (NULL);
	return (ft_remplissage(s, copy, c));
}
