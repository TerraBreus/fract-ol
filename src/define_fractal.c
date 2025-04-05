/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:12:16 by zivanov           #+#    #+#             */
/*   Updated: 2025/04/05 16:51:12 by zivanov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	set_mandelbrot(t_fractal *fractal, char *str)
{
	fractal->name = ft_strdup(str);
	if (fractal->name == NULL)
		exit_program(fractal, EXIT_FAILURE);
	fractal->is_julia = false;
	return (true);
}

static void	set_julia_constant(double r, double i, t_fractal *fractal)
{
	fractal->julia_r = r;
	fractal->julia_i = i;
}

static void	parse_julia_set(t_fractal *fractal, int julia_set)
{
	if (julia_set == 0)
		set_julia_constant(0.285, 0.0, fractal);
	else if (julia_set == 1)
		set_julia_constant(0.285, 0.01, fractal);
	else if (julia_set == 2)
		set_julia_constant(0.45, 0.1428, fractal);
	else if (julia_set == 3)
		set_julia_constant(-0.70176, -0.3842, fractal);
	else if (julia_set == 4)
		set_julia_constant(-0.835, -0.2321, fractal);
	else if (julia_set == 5)
		set_julia_constant(-0.8, 0.156, fractal);
	else if (julia_set == 6)
		set_julia_constant(-0.7269, 0.1889, fractal);
	else if (julia_set == 7)
		set_julia_constant(0.0, 0.8, fractal);
	else if (julia_set == 8)
		set_julia_constant(0.35, 0.35, fractal);
	else if (julia_set == 9)
		set_julia_constant(0.4, 0.4, fractal);
}

bool	set_julia(t_fractal *fractal, char **argv)
{
	int		julia_set;

	julia_set = ft_atoi(argv[2]);
	if (julia_set >= 0 && julia_set <= 9)
		parse_julia_set(fractal, julia_set);
	fractal->name = ft_strdup(argv[1]);
	if (fractal->name == NULL)
		exit_program(fractal, EXIT_FAILURE);
	fractal->is_julia = true;
	return (true);
}
