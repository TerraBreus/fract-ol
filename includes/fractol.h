/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:55:25 by zivanov           #+#    #+#             */
/*   Updated: 2025/04/07 15:42:54 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*---I N C L U D E S---*/

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

/*---I N S T R U C T I O N S---*/

# define USAGE "\n\
Usage:\n\n\
./fractol mandelbrot\n\
or\n\
./fractol julia <0-9>\n\n\
For the julia fractal, there are 10 sets in total to choose from.\n\
To see the possible constants for the julia set type:\n\
./fractol julia_constants\n\n\
In addition, the flag `-i` can be given to define the amount of iterations\n\
which consequently defines the quality of the fractal\n\
If no flag or an incorrect value is given to the flag, a standard iteration\n\
of 20 is put through\n\
Example: ./fractol julia 2 -i 20\n\n"

# define JULIA_CONSTANTS " \
0. c = 0.285 + 0i\n \
1. c = 0.285 + 0.01i\n \
2. c = 0.45 + 0.1428i \n \
3. c = -0.70176 - 0.3842i \n \
4. c = -0.835 - 0.2321\n \
5. c = -0.8 + 0.156i\n \
6. c = -0.7269 + 0.1889i\n \
7. c = 0 + 0.8i\n \
8. c = 0.35 + 0.35i\n \
9. c = 0.4 + 0.4i\n"

# define LEGEND "\
Move around  =  arrow keys  \
Zoom in/out  =  scrollwheel  \
Reset  =  r" 

/*---C O N S T A N T S---*/

# define WIDTH 600
# define HEIGHT 600
# define HYPOTENUSE 2
# define MAX_ITERATIONS 20

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define MANDELBROT_COLOR 0x800080

//--KEYPRESS-CONTSANTS--
# define DESTROY_WINDOW 17
# define ESCAPE 65307
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define R_KEY 114

/*---S T R U C T U R E S---*/

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*mlx_window;

	t_img	img;

	char	*name;
	int		max_i;
	double	window_map;
	double	color_map;
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	hypotenuse_sq;

	bool	is_julia;
	double	julia_r;
	double	julia_i;
}	t_fractal;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_compl;

/*---P R O T O T Y P E S---*/

//-MAIN FUNCTIONS-
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

//--GENERAL-UTILS-
bool	is_input_parsed(t_fractal *fractal, int argc, char **argv);

//-MATH-UTILS-
t_compl	sum_compl(t_compl a, t_compl b);
t_compl	sq_compl(t_compl z);
double	ft_map(double old_min, double old_max, double new_min, double new_max);
int		ft_atoi(const char *str);

//-FRACTAL-UTILS-
bool	set_mandelbrot(t_fractal *fractal, char *str);
bool	set_julia(t_fractal *fractal, char **argv);

//-STRING-UTILS-
char	*ft_strdup(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *str, int fd);
int		print_legend(t_fractal *f);

//-EXIT-UTILS-
void	exit_program(t_fractal *fractal, int exit_status);
void	exit_on_julia_constants(void);

//-EVENT-UTILS
void	check_events(t_fractal *fractal);

#endif
