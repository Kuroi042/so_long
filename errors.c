/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:22 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/18 01:03:26 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void	openber(int fd)
{
	if (fd == -1)
	{
		printf("open error");
		exit(0);
	}
}

void	N_line_errors(t_mymlx *mymlx)
{
	if (!mymlx->map.map_str)
	{
		printf("map is empty\n");
		exit(0);
	}
	if (mymlx->map.map_str[0] == '\n')
	{
		printf("empty lines in map \n");
		exit(0);
	}
}

void	line_count(t_mymlx *mymlx)
{
	if (mymlx->map.map_line_counter != mymlx->map.num_rows)
	{
		printf("error the map rows element are not correct \n");
		exit(0);
	}
}

void	check_num_col(t_mymlx *mymlx)
{
	int	i;

	i = 0;
	while (i < mymlx->map.num_rows)
	{
		if (mymlx->map.num_col != len(mymlx->map.splited[i]))
		{
			printf("error the map col element are not correct !\n");
			exit(0);
		}
		i++;
	}
}
