/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   exit_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/01 16:57:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/01 17:03:47 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_freestr(char *str)
{
	if (str != NULL)
		free(str);
	else
		ft_putstr_fd("Trying to free NULL pointer\n", 2);
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
	ft_freestr(fractal->name);
	exit();
}
