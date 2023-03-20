/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:31:07 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/20 18:37:03 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
// count the coin after and befor flood
void	coin_checker_path(char **splited, t_mymlx *mymlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mymlx->map.num_rows)
	{
		j = 0;
		while (j < mymlx->map.num_col)
		{
			if (splited[i][j] == 'C')
				mymlx->path_coin++;
			j++;
		}
		i++;
	}
}

void	findexit(char **splited, t_mymlx *mymlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mymlx->map.num_rows)
	{
		j = 0;
		while (j < mymlx->map.num_col)
		{
			if (splited[i][j] == 'E')
				mymlx->exitfound = -1;
			j++;
		}
		i++;
	}
}

void	player_position(char **splited, int path_x, int path_y, t_mymlx *mymlx)
{
	while (path_x < mymlx->map.num_rows && path_x >= 0)
	{
		path_y = 0;
		while (path_y < mymlx->map.num_col && path_y >= 0)
		{
			if (splited[path_x][path_y] == 'P')
			{
				big_path_if(splited, path_x, path_y, mymlx);
			}
			path_y++;
		}
		path_x++;
	}
}

void	big_path_if(char **splited, int pathx, int pathy, t_mymlx *mymlx)
{
	if (splited[pathx][pathy] == 'P')
	{
		if ((pathx >= 0 && splited[pathx - 1][pathy] == '0') || splited[pathx
			- 1][pathy] == 'C' || splited[pathx - 1][pathy] == 'E')
			splited[pathx - 1][pathy] = 'P';
		if ((pathx < mymlx->map.num_rows - 1 && splited[pathx
					+ 1][pathy] == '0') || splited[pathx + 1][pathy] == 'C'
			|| splited[pathx + 1][pathy] == 'E')
			splited[pathx + 1][pathy] = 'P';
		if ((pathy >= 0 && splited[pathx][pathy - 1] == '0')
			|| splited[pathx][pathy - 1] == 'C' || splited[pathx][pathy
			- 1] == 'C' || splited[pathx][pathy - 1] == 'E')
			splited[pathx][pathy - 1] = 'P';
		if ((pathy < mymlx->map.num_col - 1 && splited[pathx][pathy + 1] == '0')
			|| splited[pathx][pathy + 1] == 'C' || splited[pathx][pathy
			+ 1] == 'E')
			splited[pathx][pathy + 1] = 'P';
	}
}

void	checker(t_mymlx *mymlx)
{
	int	g;
	int	k;
	int	m;

	coin_checker_path(mymlx->map.maptester, mymlx);
	k = mymlx->path_coin;
	g = 0;
	while (g != mymlx->map.num_col)
	{
		player_position(mymlx->map.maptester, mymlx->m, mymlx->n, mymlx);
		g++;
	}
	coin_checker_path(mymlx->map.maptester, mymlx);
	m = mymlx->path_coin;
	if (k != m)
	{
		ft_printf("map is invalid\n");
				 vree(mymlx);
		exit(1);
	}
	findexit(mymlx->map.maptester, mymlx);
	if (mymlx->exitfound == -1)
	{
		ft_printf("map is invalid\n");
				 vree(mymlx);
		exit(1);
	}
}
