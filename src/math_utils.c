/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   math_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 18:17:15 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/31 18:19:57 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(double old_min, double old_max, double new_min, double new_max)
{
	return ((new_max - new_min) / (old_max - old_min));
}
