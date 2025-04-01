/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   str_utils.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/01 17:04:00 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/01 17:23:33 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_strdup(char *str)
{
	int		length;
	char	*result;

	if (str == NULL)
		return (NULL);
	length = 0;
	while (str[length] != '\0')
		length++;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
	{
//		ft_error_malloc();		//TODO
		return (NULL);
	}
	result[length] = '\0';
	while (--length >= 0)
		result[length] = str[length];
	return (result);
}
	
