/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   math_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 18:17:15 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/05 14:52:00 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_compl(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

// SQUARING COMPLEX NUMBERS:
// (a + b)^2 = a^2 + b^2 + 2ab
// (a + bi)^2 = a^2 + (b^2)*(i^2) + 2abi
// (a + bi)^2 = a^2 - b^2 + 2abi
// in function: z.r = a && z.i = b

t_complex	sq_compl(t_complex z)
{
	t_complex	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = (2 * z.r * z.i);
	return (result);
}

double	ft_map(double old_min, double old_max, double new_min, double new_max)
{
	return ((new_max - new_min) / (old_max - old_min));
}
