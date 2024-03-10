/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 15:06:33 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 14:12:58 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_win(t_data *data)
{
	mlx_terminate(data->mlx);
	ft_printf("You won!\nTotal moves: [%d]\n", data->moves);
	exit(0);
}

static void	ft_exit(t_data *data)
{
	mlx_terminate(data->mlx);
	ft_write_error("Exit\n\"Game!\" has been closed\n");
}

static void	ft_close_hook(void *param)
{
	ft_exit(param);
}

static void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(data);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move(data, 'y', UP);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move(data, 'y', DOWN);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move(data, 'x', LEFT);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		ft_move(data, 'x', RIGHT);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_matrix	*map;

	map = malloc(sizeof(t_matrix));
	data = malloc(sizeof(t_data));
	if (argc != 2)
		ft_write_error("Error\nUsage: \"./so_long mappath/mapname.ber\"\n");
	if (argc == 2)
	{
		ft_window_size(data, argv);
		ft_malloc_grid(map, data->max_lines, data->max_chars + 1);
		ft_init(data, map);
		fill_matrix(data, argv, data->max_chars);
		data->mlx = mlx_init(data->size_x, data->size_y, "Game!", false);
		ft_create_map(data);
		ft_check_content(data);
		mlx_key_hook(data->mlx, ft_keyhook, data);
		mlx_close_hook(data->mlx, ft_close_hook, data);
		mlx_loop(data->mlx);
		mlx_terminate(data->mlx);
	}
	ft_free_grid(map);
	free(data);
	free(map);
	return (0);
}
