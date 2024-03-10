/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 09:29:53 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 13:35:55 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_collect(t_data *data)
{
	data->collected++;
	data->map->grid[data->p_y][data->p_x] = '0';
	mlx_image_to_window(data->mlx, data->background,
		data->p_x * IMG_W, data->p_y * IMG_H);
	data->player->instances[0].z++;
}

static void	ft_player_move(t_data *data, char pos, int dir)
{
	if (pos == 'y' && dir == UP
		&& data->map->grid[data->p_y - 1][data->p_x] != '1')
	{
		data->player->instances[0].y -= IMG_H;
		ft_printf("Moves: %d\n", ++data->moves);
	}
	if (pos == 'y' && dir == DOWN
		&& data->map->grid[data->p_y + 1][data->p_x] != '1')
	{
		data->player->instances[0].y += IMG_H;
		ft_printf("Moves: %d\n", ++data->moves);
	}
	if (pos == 'x' && dir == LEFT
		&& data->map->grid[data->p_y][data->p_x - 1] != '1')
	{
		data->player->instances[0].x -= IMG_W;
		ft_printf("Moves: %d\n", ++data->moves);
	}
	if (pos == 'x' && dir == RIGHT
		&& data->map->grid[data->p_y][data->p_x + 1] != '1')
	{
		data->player->instances[0].x += IMG_W;
		ft_printf("Moves: %d\n", ++data->moves);
	}
}

void	ft_move(t_data *data, char pos, int dir)
{
	ft_player_move(data, pos, dir);
	if (pos == 'y'
		&& data->map->grid[data->p_y + 1 * dir][data->p_x] != '1')
		data->p_y = data->p_y + 1 * dir;
	if (pos == 'x'
		&& data->map->grid[data->p_y][data->p_x + 1 * dir] != '1')
		data->p_x = data->p_x + 1 * dir;
	if (data->map->grid[data->p_y][data->p_x] == 'C')
		ft_collect(data);
	if (data->map->grid[data->p_y][data->p_x] == 'E')
	{
		if (data->coins == data->collected)
			ft_win(data);
		else
			ft_printf("Need %d more fish to exit\n",
				data->coins - data->collected);
	}
}
