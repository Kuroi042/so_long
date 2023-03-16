/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coincounter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:38:30 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/16 17:35:39 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	coin_counter(int i, int j, char **splited, t_mymlx *mymlx)
{
	if (splited[i][j] == 'C')
	{
		mymlx->coincounter += 1;
		splited[i][j] = '0';
	}
	if (mymlx->num_coins == mymlx->coincounter)
		mymlx->coin_yes = 1;
}

void	press_escap(t_mymlx *mymlx)
{
	mlx_destroy_window(mymlx->mlx, mymlx->mlx_win);
	exit(0);
}

int	pressex(int keycode)
{
	keycode = 17;
	exit(0);
	return (0);
}
