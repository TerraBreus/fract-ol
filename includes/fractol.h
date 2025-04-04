/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:55:25 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/04 10:00:46 by terramint        ###   ########.fr       */
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
# define USAGE "\
Welcome to the how_to_fractal instructions page!\n\
Simply put, you have 2 options: \n\n\
./fractol mandelbrot\n\
or\n\
./fractol julia <1-10>\n\n\
For the julia set an extra number between 1 and 10 \n\
is required to establish which constants will be used.\n"
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

/*TODO Ability to control quality (max iterations)*/

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
}	t_complex;

/*---P R O T O T Y P E S---*/

//-MAIN FUNCTIONS-
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

//--GENERAL-UTILS-
bool	is_input_parsed(t_fractal *fractal, int argc, char **argv);

//-MATH-UTILS-
t_complex	sum_compl(t_complex a, t_complex b);
t_complex	sq_compl(t_complex z);
double	ft_map(double old_min, double old_max, double new_min, double new_max);

//-STRING-UTILS-
char	*ft_strdup(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *str, int fd);

//-EXIT-UTILS-
void	exit_program(t_fractal *fractal, int exit_status);

//-EVENT-UTILS
void	check_events(t_fractal *fractal);


#endif
