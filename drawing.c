/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:31:50 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/16 01:24:30 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	projec(int x, int y, t_mymlx *mymlx)
{
	mymlx->wall = mlx_xpm_file_to_image(mymlx->mlx, "xpms/waall.xpm", &x, &y);
	mymlx->sand = mlx_xpm_file_to_image(mymlx->mlx, "xpms/sand.xpm", &x, &y);
	mymlx->joseph = mlx_xpm_file_to_image(mymlx->mlx, "xpms/jooseph.xpm", &x,
			&y);
	mymlx->coin = mlx_xpm_file_to_image(mymlx->mlx, "xpms/bassit.xpm", &x, &y);
	mymlx->exit = mlx_xpm_file_to_image(mymlx->mlx, "xpms/kherja.xpm", &x, &y);
	// mymlx->enter = mlx_xpm_file_to_image(mymlx->mlx, "xpms/dkhel.xpm", &x, &y);
}

void	drawingxpm(int i, int j, char **splited, t_mymlx *mymlx)
{
	mymlx->num_coins = 0;
	while (i < mymlx->map.num_rows)
	{
		j = 0;
		while (j < mymlx->map.num_col)
				{
			// if (splited[i][j] == 'E')
			// 	mymlx->map.e_found = 1;
			if (splited[i][j] == '1')
				mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->wall,
					j * 32, i * 32);
			if (splited[i][j] == '0' || splited[i][j] == 'E'
				|| splited[i][j] == 'P' || splited[i][j] == 'C')
			{
				mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->sand,
					j * 32, i * 32);
			}
			
			drawingxpsuite(mymlx->map.splited, i, j, mymlx);
			j++;
		}
		i++;
	}
}
void find_e(t_mymlx *mymlx){

	if (mymlx->map.e_found != 1){
		printf("eerror map\n");
		exit(0);
	}
}

void	drawingxpsuite(char **splited, int i, int j, t_mymlx *mymlx)
{
	if (splited[i][j] == 'P')
	{
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->joseph, j
			* 32, i * 32);
		mymlx->player.player_x = i;
		mymlx->player.player_y = j;
	}
	if (splited[i][j] == 'C')
	{
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->coin, j * 32,
			i * 32);
		mymlx->num_coins++;
	}
	if (splited[i][j] == 'E')
	{
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->exit, j * 32,
			i * 32);
		mymlx->exit_x = i;
		mymlx->exit_y = j;
	}
}

void	rassam_lmahir(int i, int j, void *image, t_mymlx *mymlx)
{
	//all coin collected and player went throug the exit
	if (mymlx->map.splited[i][j] == 'E' && mymlx->coin_yes == 1)
		exit(0);
	else
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, image, j * 32, i
			* 32);
}

// case of player daz fo9 exit && coin mamjmou3inch
void	printexit(t_mymlx *mymlx)
{
	
	if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y]
		== 'E' && mymlx->coincounter != mymlx->num_coins)
	{
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->exit,
			mymlx->exit_y * 32, mymlx->exit_x * 32);
					
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->joseph,
			mymlx->exit_y * 32, mymlx->exit_x * 32);

	}
	// exit print every time solo case of player delete the exit after passing by
	else if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y] != 'E'){
		mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->exit,
			mymlx->exit_y * 32, mymlx->exit_x * 32);
			printf("hahaha\n");
	}
}

// void	coin_counter(int i, int j, char **splited, t_mymlx *mymlx)
// {
// 	if (splited[i][j] == 'C')
// 	{
// 		mymlx->coincounter += 1;
// 		splited[i][j] = '0';
// 	}
// 	if (mymlx->num_coins == mymlx->coincounter)
// 	{
// 		mymlx->coin_yes = 1;
// 		mlx_string_put(mymlx->mlx, mymlx->mlx_win, 12, 10, 0xffffff,
// 			"all coins collected !");
// 	}
// }
