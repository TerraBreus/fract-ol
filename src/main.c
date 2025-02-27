/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/26 17:01:56 by zivanov        #+#    #+#                */
/*   Updated: 2025/02/27 14:19:00 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel) / 8);
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int size;

	size = 50;

	i = -1;
	while (++i < size)
	{
		my_mlx_pixel_put(data, x + i, y, color);
		my_mlx_pixel_put(data, x, y + i, color);
		my_mlx_pixel_put(data, x + size, y + i, color);
		my_mlx_pixel_put(data, x + i, y + size, color);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	draw_square(&img, 1920/2, 1080/2, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	(void)mlx_win;
	(void)img;
	mlx_loop(mlx);
	return (0);
}
