/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_nd_coin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:30 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/29 02:39:09 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	press_escap(t_mymlx *mymlx)
{
	mlx_destroy_window(mymlx->mlx, mymlx->mlx_win);
	vree(mymlx);
	exit(0);
}

int	pressex(int keycode)
{
	keycode = 17;
	return (0);
}

void	thedestroyer(t_mymlx *mymlx)
{
	if (mymlx->mlx_win)
	{
		mlx_destroy_image(mymlx->mlx, mymlx->wall);
		mlx_destroy_image(mymlx->mlx, mymlx->coin);
		mlx_destroy_image(mymlx->mlx, mymlx->joseph);
		mlx_destroy_image(mymlx->mlx, mymlx->exit);
		mlx_destroy_image(mymlx->mlx, mymlx->sand);
		mlx_destroy_window(mymlx->mlx, mymlx->mlx_win);
	}
}

void	vree(t_mymlx *mymlx)
{
	mymapfree(mymlx->splited, mymlx);
	mymapfree(mymlx->maptester, mymlx);
	mymlx = NULL;
	free(mymlx);
}

void	mymapfree(char **map, t_mymlx *mymlx)
{
	int	i;

	i = 0;
	while (i <= mymlx->num_rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
