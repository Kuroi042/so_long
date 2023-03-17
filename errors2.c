/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:03 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/17 04:50:46 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	berber(char *str)
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		printf(".ber is not found\n");
		exit(0);
	}
}

void	line_count(t_mymlx *mymlx)
{
	if (mymlx->map.map_line_counter != mymlx->map.num_rows)
	{
		printf("map.ber lines are not correct ! \n");
		exit(0);
	}
}

void	allerror(t_mymlx *mymlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	line_count(mymlx);
	check_num_col(mymlx);
	inputter(i, j, mymlx);
	permetre(mymlx);
	checker(mymlx);
}

void	inputter(int j, int k, t_mymlx *mymlx)
{
	j = 0;
	k = 0;
	while (k < mymlx->map.num_rows)
	{
		while (j < mymlx->map.num_col)
		{
			if (mymlx->map.splited[k][j] == 'E')
				mymlx->exitdiali++;
			if (mymlx->map.splited[k][j] == 'P')
				mymlx->playerdiali++;
			if (mymlx->map.splited[k][j] == 'C')
				mymlx->colldiali++;
			j++;
		}
		j = 0;
		k++;
	}
	if (mymlx->colldiali == 0 || mymlx->playerdiali != 1
		|| mymlx->exitdiali != 1)
	{
		printf("error 'E' 'P' 'C' not found  in the map\n");
		exit(0);
	}
}
