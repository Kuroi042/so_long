/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:11:14 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/02 00:18:52 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mlx(t_mymlx *mymlx)
{
	mymlx->mlx = mlx_init();
	mymlx->mlx_win = mlx_new_window(mymlx->mlx, mymlx->num_col * 32,
			mymlx->num_rows * 32, "3ayn dahrek");
	projec(mymlx->m, mymlx->n, mymlx);
	drawingxpm(mymlx->i, mymlx->j, mymlx->splited, mymlx);
	mlx_hook(mymlx->mlx_win, 17, 0, pressex, mymlx);
	mlx_key_hook(mymlx->mlx_win, key_press, mymlx);
	mlx_loop(mymlx->mlx);
}
