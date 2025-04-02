/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 16:18:27 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/02 10:30:01 by terramint        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	img_init(t_fractal *fractal)
{
	t_img	*img;

	img = &(fractal->img);

	img->mlx_img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (img->mlx_img == NULL)
		exit_program(fractal);	//TODO
	img->addr = mlx_get_data_addr(img->mlx_img, \
		&(img->bpp), &(img->size_line), &(img->endian));
}

void	fractal_init(t_fractal *fractal)
{
	if (fractal->name == NULL)
//		ft_error_name();	//TODO name assignment should be in establish_fractal

	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		exit_program(fractal);	//TODO

	fractal->mlx_window = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_ptr == NULL)
		exit_program(fractal);
	
	fractal->max_i = MAX_ITERATIONS;
	fractal->window_map = ft_map(0, WIDTH,-2, 2);
	fractal->zoom = 1;
	fractal->hypotenuse_sq = HYPOTENUSE * HYPOTENUSE;
	fractal->color_map = ft_map(BLACK, WHITE, 0, fractal->max_i);
	img_init(fractal);
}	
