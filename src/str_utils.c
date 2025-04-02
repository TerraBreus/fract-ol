/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   str_utils.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/01 17:04:00 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/02 19:38:19 by zivanov        ########   odam.nl        */
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
	
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	len;
	
	if (str == NULL)
		return ;
	len = 0;
	while (str[len] != '\0') 
		len++;
	write(fd, str, len);
}
