/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 15:31:46 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 16:21:56 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}

static int	ft_count_lines(int fd, int x, int img_w)
{
	char	*line;
	int		linecount;
	int		i;

	i = 0;
	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if ((int)ft_linelen(line) != (x / img_w)
			|| (ft_len(line) == 1 && *line != '\n'))
		{
			free(line);
			ft_write_error("Error\nMap is not rectangular\n");
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}

void	ft_window_size(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_write_error("Error\nInvalid map or map_path\n");
		exit(1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_len(argv[1])) == NULL)
	{
		ft_write_error("Error\nMap has to be \".ber\"\n");
		exit(1);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
	data->max_chars = (data->size_x / IMG_W);
	data->max_lines = (data->size_y / IMG_H);
}

static void	ft_place_player(t_data *data)
{
	data->map->cols = 0;
	data->map->rows = 0;
	while (data->map->rows < data->max_lines)
	{
		if (data->map->grid[data->map->rows][data->map->cols] == 'P')
			ft_put_player(data);
		if (data->map->cols < data->max_chars)
			data->map->cols++;
		else
		{
			data->map->rows++;
			data->map->cols = 0;
		}
	}
}

void	ft_create_map(t_data *data)
{
	data->map->cols = 0;
	data->map->rows = 0;
	ft_put_background(data);
	while (data->map->rows < data->max_lines)
	{
		if (data->map->grid[data->map->rows][data->map->cols] == 'E')
			ft_put_exit(data);
		else if (data->map->grid[data->map->rows][data->map->cols] == '1')
			ft_put_wall(data);
		else if (data->map->grid[data->map->rows][data->map->cols] == 'C')
			ft_put_coin(data);
		if (data->map->cols < data->max_chars)
			data->map->cols++;
		else
		{
			data->map->rows++;
			data->map->cols = 0;
		}
	}
	ft_put_bar(data);
	ft_put_moves(data, "Moves:", 15, 5);
	ft_put_score(data, "000", 150, 10);
	ft_place_player(data);
}
