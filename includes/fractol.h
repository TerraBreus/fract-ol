/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fractol.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:55:25 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/31 18:53:55 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//---I N C L U D E S---\\

# include "includes/mlx.h"
# include <unistd.h>
# include <stdlib.h>

//---C O N S T A N T S---\\

# define WIDTH 600
# define HEIGHT 600
# define HYPOTENUSE 2
# define MAX_ITERATIONS 100

//TODO
//# define WHITE
//# define BLACK
//# define MANDELBROT_COLOR

//TODO Ability to control quality (max iterations)

//---S T R U C T U R E S---\\

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struc s_fractal
{
	void	*mlx_ptr;
	void	*mlx_window;

	t_img	img;

	char	*name;
	int		max_i;
	double	window_map;
	double	zoom;
	double	hypotenuse_sq;
}	t_fractal;

typedef struc s_complex
{
	double	r;
	double	i;
}	t_complex;

//---P R O T O T Y P E S---

#endif
