/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/26 13:52:35 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 16:20:34 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_init(t_data *data, t_matrix *map)
{
	data->map = map;
	data->collected = 0;
	data->moves = 0;
	data->access_coins = 0;
	data->access_exit = 0;
}

void	*ft_draw_rect(mlx_t *mlx,
	uint32_t width, uint32_t height, uint32_t color)
{
	mlx_image_t		*image;
	uint32_t		x;
	uint32_t		y;

	image = mlx_new_image(mlx, width, height);
	x = 0;
	y = 1;
	while (y < height)
	{
		mlx_put_pixel(image, x, y, color);
		if (y + 1 == height)
		{
			y = 0;
			x++;
			if (x + 1 == width)
				break ;
		}
		y++;
	}
	return (image);
}

void	ft_put_bar(t_data *data)
{
	data->score = ft_draw_rect(data->mlx, 250, 50, 0x000000FF);
	mlx_image_to_window(data->mlx, data->score, 10, 10);
}

void	ft_put_moves(t_data *data, char *str, int x, int y)
{
	mlx_image_t	*ptr;

	ptr = mlx_put_string(data->mlx, str, x, y);
	mlx_resize_image(ptr, 130, 55);
}

void	ft_put_score(t_data *data, char *str, int x, int y)
{
	mlx_image_t	*ptr;

	ptr = mlx_put_string(data->mlx, str, x, y);
	mlx_resize_image(ptr, 100, 50);
}
