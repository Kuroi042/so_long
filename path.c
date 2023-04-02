/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:31:07 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/01 23:04:14 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
// count the coin after and befor flood
void	coin_checker_path(char **splited, t_mymlx *mymlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mymlx->num_rows)
	{
		j = 0;
		while (j < mymlx->num_col)
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
	while (i < mymlx->num_rows)
	{
		j = 0;
		while (j < mymlx->num_col)
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
	while (path_x < mymlx->num_rows && path_x >= 0)
	{
		path_y = 0;
		while (path_y < mymlx->num_col && path_y >= 0)
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
		if ((pathx < mymlx->num_rows - 1 && splited[pathx + 1][pathy] == '0')
			|| splited[pathx + 1][pathy] == 'C' || splited[pathx
			+ 1][pathy] == 'E')
			splited[pathx + 1][pathy] = 'P';
		if ((pathy >= 0 && splited[pathx][pathy - 1] == '0')
			|| splited[pathx][pathy - 1] == 'C' || splited[pathx][pathy
			- 1] == 'C' || splited[pathx][pathy - 1] == 'E')
			splited[pathx][pathy - 1] = 'P';
		if ((pathy < mymlx->num_col - 1 && splited[pathx][pathy + 1] == '0')
			|| splited[pathx][pathy + 1] == 'C' || splited[pathx][pathy
			+ 1] == 'E')
			splited[pathx][pathy + 1] = 'P';
	}
}

void	checker(t_mymlx *mymlx)
{
	coin_checker_path(mymlx->maptester, mymlx);
	mymlx->coin_before_flood = mymlx->path_coin;
	mymlx->zero = 0;
	while (mymlx->zero != mymlx->num_col)
	{
		player_position(mymlx->maptester, mymlx->m, mymlx->n, mymlx);
		mymlx->zero++;
	}
	coin_checker_path(mymlx->maptester, mymlx);
	mymlx->coin_after_flood = mymlx->path_coin;
	if (mymlx->coin_before_flood != mymlx->coin_after_flood)
	{
		ft_printf("map is invalid\n");
		vree(mymlx);
		exit(1);
	}
	findexit(mymlx->maptester, mymlx);
	if (mymlx->exitfound == -1)
	{
		ft_printf("map is invalid\n");
		vree(mymlx);
		exit(1);
	}
}
