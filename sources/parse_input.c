/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 13:46:53 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 13:18:31 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	dfs(t_data *data, bool **visited, int x, int y)
{
	int	result;

	result = 0;
	if (data->access_coins == data->coins && data->access_exit == 1)
		return (1);
	if (visited[y][x] || x < 0 || x >= data->max_chars - 1 || y < 0
		|| y >= data->max_lines -1 || data->map->grid[y][x] == '1')
		return (0);
	visited[y][x] = true;
	if (data->map->grid[y][x] == 'C')
		data->access_coins++;
	if (data->map->grid[y][x] == 'E')
		data->access_exit = 1;
	result |= dfs(data, visited, x + 1, y);
	result |= dfs(data, visited, x - 1, y);
	result |= dfs(data, visited, x, y + 1);
	result |= dfs(data, visited, x, y - 1);
	return (result);
}

static void	ft_check_access(t_data *data)
{
	int		i;
	bool	**visited;

	i = 0;
	visited = ft_calloc(data->max_lines, sizeof(bool *));
	while (i < data->max_lines)
	{
		visited[i] = ft_calloc(data->max_chars, sizeof(bool *));
		i++;
	}
	if (!dfs(data, visited, data->p_x, data->p_y))
		ft_write_error("Error\nMap is unbeatable\n");
	i = 0;
	while (i < data->max_lines)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static void	ft_check_borders(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->max_lines)
	{
		if ((int)ft_len(data->map->grid[y]) != data->max_chars)
			ft_write_error("Error\nWrong map dimensions");
		x = 0;
		while (x < data->max_chars)
		{
			if (data->map->grid[y][x] != '0' && data->map->grid[y][x] != '1' &&
				data->map->grid[y][x] != 'C' && data->map->grid[y][x] != 'P' &&
				data->map->grid[y][x] != 'E')
				ft_write_error("Error\nNon valid map input: 1,0,P,E,C only\n");
			else if ((y == 0 || x == 0) && data->map->grid[y][x] != '1')
				ft_write_error("Error\nMap has to be surrounded by walls\n");
			else if ((y == data->max_lines - 1 || x == data->max_chars - 1)
				&& data->map->grid[y][x] != '1')
				ft_write_error("Error\nMap has to be surrounded by walls\n");
			x++;
		}
		y++;
	}
	ft_check_access(data);
}

void	ft_check_content(t_data *data)
{
	int	y;
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	data->coins = 0;
	y = 0;
	while (y < data->max_lines)
	{
		player += ft_count_c(data->map->grid[y], 'P');
		exit += ft_count_c(data->map->grid[y], 'E');
		data->coins += ft_count_c(data->map->grid[y], 'C');
		y++;
	}
	if (player != 1)
		ft_write_error("Error\nMap does not contain one player\n");
	if (exit == 0)
		ft_write_error("Error\nNo exit found in map\n");
	if (data->coins == 0)
		ft_write_error("Error\nNo coins found in map\n");
	ft_check_borders(data);
}

void	fill_matrix(t_data *data, char **argv, int cols)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	j = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		i = 0;
		while (i < cols)
		{
			data->map->grid[j][i] = line[i];
			i++;
		}
		data->map->grid[j][i] = '\0';
		free(line);
		j++;
	}
	close(fd);
}
