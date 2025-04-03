/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:18:27 by zivanov           #+#    #+#             */
/*   Updated: 2025/04/03 15:40:57 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	img_init(t_fractal *fractal)
{
	t_img	*img;

	img = &(fractal->img);

	img->mlx_img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (img->mlx_img == NULL)
		exit_program(fractal, EXIT_FAILURE);
	img->addr = mlx_get_data_addr(img->mlx_img, \
		&(img->bpp), &(img->size_line), &(img->endian));
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		exit_program(fractal, EXIT_FAILURE);

	fractal->mlx_window = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name); 
	if (fractal->mlx_window == NULL)
		exit_program(fractal, EXIT_FAILURE);
	
	fractal->max_i = MAX_ITERATIONS;
	fractal->window_map = ft_map(0, WIDTH,-1, 1);
	fractal->zoom = 1.0;
	fractal->hypotenuse_sq = HYPOTENUSE * HYPOTENUSE;
	fractal->color_map = ft_map(0, fractal->max_i, BLACK, WHITE);
	img_init(fractal);
}	
