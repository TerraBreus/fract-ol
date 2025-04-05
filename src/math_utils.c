/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:17:15 by zivanov           #+#    #+#             */
/*   Updated: 2025/04/05 15:57:57 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_compl	sum_compl(t_compl a, t_compl b)
{
	t_compl	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

// SQUARING COMPLEX NUMBERS:
// (a + b)^2 = a^2 + b^2 + 2ab
// (a + bi)^2 = a^2 + (b^2)*(i^2) + 2abi
// (a + bi)^2 = a^2 - b^2 + 2abi
// in function: z.r = a && z.i = b

t_compl	sq_compl(t_compl z)
{
	t_compl	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = (2 * z.r * z.i);
	return (result);
}

double	ft_map(double old_min, double old_max, double new_min, double new_max)
{
	return ((new_max - new_min) / (old_max - old_min));
}
