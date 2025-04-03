/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   exit_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/01 16:57:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/03 13:00:42 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_freestr(char *str)
{
	if (str != NULL)
		free(str);
	//else
	//	ft_putstr_fd("Trying to free NULL pointer\n", 2); //TODO
}

/* Plan to use this function whenever an error
** occurs and we need to free everything
** so we can close/exit the program without leaks
** Might want to pass some kind of enum error.
** Still considering whether function also called
** for exitting program at users command.
*/

void	exit_program(t_fractal *fractal)	//TODO
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.mlx_img);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	ft_freestr(fractal->name);
	exit(EXIT_FAILURE);
}
