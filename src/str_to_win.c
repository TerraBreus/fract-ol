/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   str_to_win.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/07 15:20:40 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/07 15:41:23 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int	print_legend(t_fractal *f)
{
	if (mlx_string_put(\
		f->mlx_ptr, \
		f->mlx_window, \
		0, \
		WIDTH - 20, \
		BLACK, \
		LEGEND) == -1 )
	{
		exit_program(f, EXIT_FAILURE);
	}
	return (0);
}
