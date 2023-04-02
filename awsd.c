/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awsd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:33:20 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/30 21:27:53 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_press(int keycode, t_mymlx *mymlx)
{
	if (keycode == 13)
		press_w(mymlx);
	if (keycode == 1)
		press_s(mymlx);
	if (keycode == 0)
		press_a(mymlx);
	if (keycode == 2)
		press_d(mymlx);
	if (keycode == 53)
		press_escap(mymlx);
	return (0);
}

void	press_w(t_mymlx *mymlx)
{
	if (mymlx->splited[mymlx->player.player_x
			- 1][mymlx->player.player_y] != '1')
	{
		rassam(mymlx->player.player_x - 1, mymlx->player.player_y, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x - 1, mymlx->player.player_y,
			mymlx->joseph, mymlx);
		mymlx->player.player_x--;
		mymlx->player.pas++;
		printexit(mymlx);
		coin_counter(mymlx->player.player_x, mymlx->player.player_y,
			mymlx->splited, mymlx);
		ft_printf("khotwa : +%d\n", mymlx->player.pas);
	}
}

void	press_s(t_mymlx *mymlx)
{
	if (mymlx->splited[mymlx->player.player_x
			+ 1][mymlx->player.player_y] != '1')
	{
		rassam(mymlx->player.player_x + 1, mymlx->player.player_y, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x + 1, mymlx->player.player_y,
			mymlx->joseph, mymlx);
		mymlx->player.player_x++;
		mymlx->player.pas++;
		printexit(mymlx);
		coin_counter(mymlx->player.player_x, mymlx->player.player_y,
			mymlx->splited, mymlx);
		ft_printf("khotwa: +%d\n", mymlx->player.pas);
	}
}

void	press_a(t_mymlx *mymlx)
{
	if (mymlx->splited[mymlx->player.player_x][mymlx->player.player_y
		- 1] != '1')
	{
		rassam(mymlx->player.player_x, mymlx->player.player_y - 1, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x, mymlx->player.player_y - 1,
			mymlx->joseph, mymlx);
		mymlx->player.player_y--;
		mymlx->player.pas++;
		printexit(mymlx);
		coin_counter(mymlx->player.player_x, mymlx->player.player_y,
			mymlx->splited, mymlx);
		ft_printf("khotwa : +%d\n", mymlx->player.pas);
	}
}

void	press_d(t_mymlx *mymlx)
{
	if (mymlx->splited[mymlx->player.player_x][mymlx->player.player_y
		+ 1] != '1')
	{
		rassam(mymlx->player.player_x, mymlx->player.player_y + 1, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand,
			mymlx);
		rassam(mymlx->player.player_x, mymlx->player.player_y + 1,
			mymlx->joseph, mymlx);
		mymlx->player.player_y++;
		mymlx->player.pas++;
		printexit(mymlx);
		coin_counter(mymlx->player.player_x, mymlx->player.player_y,
			mymlx->splited, mymlx);
		ft_printf("khotwa : +%d\n", mymlx->player.pas);
	}
}
