/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_imgs.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 13:48:57 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 14:16:47 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_put_background(t_data *data)
{
	int	y;
	int	x;

	data->texture = mlx_load_png("./images/background.png");
	if (data->texture == NULL)
		ft_write_error("Error\nBackground texture not found\n");
	data->background = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			mlx_image_to_window(data->mlx, data->background, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	ft_put_player(t_data *data)
{
	data->p_x = data->map->cols;
	data->p_y = data->map->rows;
	data->texture = mlx_load_png("./images/player.png");
	if (data->texture == NULL)
		ft_write_error("Error\nPlayer texture not found\n");
	data->player = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	mlx_image_to_window(data->mlx, data->player,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
}

void	ft_put_wall(t_data *data)
{
	data->texture = mlx_load_png("./images/wall.png");
	if (data->texture == NULL)
		ft_write_error("Error\nWall texture not found\n");
	data->image = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	mlx_image_to_window(data->mlx, data->image,
		(data->map->cols * IMG_W), (data->map->rows * IMG_H));
}

void	ft_put_coin(t_data *data)
{
	data->texture = mlx_load_png("./images/coin.png");
	if (data->texture == NULL)
		ft_write_error("Error\nCollectible texture not found\n");
	data->coin = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	mlx_image_to_window(data->mlx, data->coin,
		(data->map->cols * IMG_W), (data->map->rows * IMG_H));
}

void	ft_put_exit(t_data *data)
{
	data->texture = mlx_load_png("./images/exit.png");
	if (data->texture == NULL)
		ft_write_error("Error\nExit texture not found\n");
	data->image = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	mlx_image_to_window(data->mlx, data->image,
		(data->map->cols * IMG_W), (data->map->rows * IMG_H));
}
