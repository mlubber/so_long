/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/20 06:25:46 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/02/27 09:57:49 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!str1)
		i = ft_len(str2);
	else
		i = ft_len(str1) + ft_len(str2);
	out = (char *)malloc((i + 1) * sizeof(char));
	if (!out)
		return (ft_free(&str1));
	i = 0;
	while (str1 != NULL && str1[i])
	{
		out[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		out[i++] = str2[j++];
	out[i] = '\0';
	ft_free(&str1);
	return (out);
}

