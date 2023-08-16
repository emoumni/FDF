/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:52:00 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/16 19:52:01 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(size * count);
	if (!r)
		return (0);
	ft_bzero (r, size * count);
	return (r);
}
