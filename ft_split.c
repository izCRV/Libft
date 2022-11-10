/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:44:15 by aizsak            #+#    #+#             */
/*   Updated: 2022/11/10 22:12:48 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	separ(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (separ(str[i + 1], sep) == 1 && separ(str[i], sep) == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, char *from, char sep)
{
	int	i;

	i = 0;
	while (separ(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static void	*write_split(char **split, char *str, char sep)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (separ(str[i], sep) == 1)
			i++;
		else
			j = 0;
		while (separ(str[i + j], sep) == 0)
			j++;
		split[word] = (char *)malloc(sizeof(char) * (j + 1));
		if (split[word] == NULL)
			while (word > 0)
				free(split[--word]);
		return (NULL);
		write_word(split[word], str + i, sep);
		i += j;
		word++;
	}
	return ((void *)1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*str;
	int		words;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, c) == NULL)
		return (NULL);
	return (res);
}
