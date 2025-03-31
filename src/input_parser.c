/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   input_parser.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 15:02:05 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/31 15:30:39 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	show_usage(void)			//TODO implement better usage text
{	
	ft_putstr_fd("Usage: ./fract-ol mandelbrot\n", 2);
}

bool	correct_input(int argc, char **argv)
{
	char	*decapitalize;

	if (argc != 2 || argc != 4)
	{
		show_usage();
		return (false);
	}

	decapitalize = ft_strdup(ft_tolower(argv[1]));	//TODO strdup tolower
	if (decapitalize == NULL)
		ft_error_malloc();			//TODO error_malloc

	if ((ft_strncmp(argv[1], "mandelbrot") != 0) \	//TODO strncmp
		&& (ft_strncmp(argv[1], "julia") != 0))
	{
		show_usage();
		return (false);
	}
	return (true);
}
