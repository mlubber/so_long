/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 15:09:02 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 16:20:06 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libraries/MLX42/include/MLX42/MLX42.h"

# define BUFFER_SIZE 1
# define IMG_W 80
# define IMG_H 80
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_matrix
{
	int		cols;
	int		rows;
	char	**grid;
}	t_matrix;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	mlx_image_t		*coin;
	mlx_image_t		*player;
	mlx_image_t		*background;
	mlx_image_t		*score;
	int				size_x;
	int				size_y;
	int				max_chars;
	int				max_lines;
	int				coins;
	int				p_x;
	int				p_y;
	int				access_coins;
	int				access_exit;
	int				collected;
	int				moves;
	t_matrix		*map;
}	t_data;


int		ft_putchar(int c);
void	ft_putnbr(long n);
int		ft_printf(const char *format, ...);
void	ft_write_error(char *error_msg);
void	ft_window_size(t_data *data, char **argv);
char	*ft_find_line(int fd, char *str);
char	*ft_next_line(char *str);
char	*ft_rem_line(char *line);
char	*get_next_line(int fd);
char	*ft_free(char **str);
size_t	ft_len(char *str);
int		ft_linelen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
void	*ft_calloc(size_t nelem, size_t elsize);
void	ft_malloc_grid(t_matrix *matrix, int rows, int cols);
void	ft_free_grid(t_matrix *matrix);
void	fill_matrix(t_data *data, char **argv, int cols);
void	ft_check_content(t_data *data);
void	ft_put_background(t_data *data);
void	ft_put_player(t_data *data);
void	ft_put_coin(t_data *data);
void	ft_put_exit(t_data *data);
void	ft_put_wall(t_data *data);
void	ft_init(t_data *data, t_matrix *map);
int		ft_count_c(char *s, char c);
void	ft_create_map(t_data *data);
void	ft_move(t_data *data, char pos, int dir);
void	ft_win(t_data *data);
void	*ft_draw_rect(mlx_t *mlx, uint32_t width,
			uint32_t height, uint32_t color);
void	ft_put_bar(t_data *data);
void	ft_put_moves(t_data *data, char *str, int x, int y);
void	ft_put_score(t_data *data, char *str, int x, int y);
#endif
