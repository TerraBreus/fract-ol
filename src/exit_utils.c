/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   exit_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/01 16:57:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/03 13:54:25 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Plan to use this function whenever an error
** occurs and we need to free everything
** so we can close/exit the program without leaks
** Might want to pass some kind of enum error.
** Still considering whether function also called
** for exitting program at users command.
*/

void	exit_program(t_fractal *fractal, int exit_status)
{
	if (fractal->mlx_ptr != NULL)
	{
		if (fractal->img.mlx_img != NULL)
			mlx_destroy_image(fractal->mlx_ptr, fractal->img.mlx_img);
		if (fractal->mlx_window != NULL)
			mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	if (fractal->name != NULL)
		free(fractal->name);
	exit(exit_status);
}
