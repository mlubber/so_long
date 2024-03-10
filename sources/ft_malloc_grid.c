/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_grid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 14:52:22 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 13:01:36 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_malloc_grid(t_matrix *matrix, int rows, int cols)
{
	int	i;

	matrix->rows = rows;
	matrix->cols = cols;
	matrix->grid = (char **)malloc(rows * sizeof(char *));
	if (matrix->grid == NULL)
		ft_write_error("Error\nMemory allocation failed for rows.\n");
	i = 0;
	while (i < rows)
	{
		matrix->grid[i] = (char *)malloc(cols * sizeof(char));
		if (matrix->grid[i] == NULL)
			ft_write_error("Error\nMemory allocation failed for columns.\n");
		i++;
	}
}

void	ft_free_grid(t_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < matrix->rows)
	{
		free(matrix->grid[i]);
		i++;
	}
	free(matrix->grid);
}
