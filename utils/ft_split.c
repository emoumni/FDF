/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:51:34 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/18 17:19:39 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	**free_table(char **tab, int i)
{
	while (i-- > 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static char	*ft_push(const char *s, int begin, int end)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(*temp) * (end - begin + 1));
	if (!temp)
		return (NULL);
	while (begin < end)
	{
		temp[i] = s[begin];
		i++;
		begin++;
	}
	temp[i] = '\0';
	return (temp);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		begin;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ret)
		return (free_table(ret, 0));
	i = -1;
	word = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			begin = i;
		if ((i != 0 && s[i] == c && s[i - 1] != c)
			|| (s[i + 1] == '\0' && s[i] != c))
			ret[++word] = ft_push(s, begin, i + (s[i] != c));
		if (word != -1 && !ret[word])
			return (free_table(ret, word));
	}
	ret[++word] = NULL;
	return (ret);
}
