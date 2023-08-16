/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:51:29 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/18 17:20:06 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		ret[i] = s1[i];
	while (++j < s2_len)
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}
