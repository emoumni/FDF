/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:16:26 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 13:09:00 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_ipart(float n)
{
	return ((int)n);
}

float	ft_fpart(float n)
{
	if (n > 0.0f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.0f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	ft_absolute(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}
