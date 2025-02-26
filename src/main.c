/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/02/26 17:01:56 by zivanov        #+#    #+#                */
/*   Updated: 2025/02/26 18:26:05 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	(void)mlx_win;
	mlx_loop(mlx);
	return (0);
}
