/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:22 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/20 18:36:50 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"


void	openber(int fd)
{
	if (fd == -1)
	{
		ft_printf("open error");
		exit(0);
	}
}

void	N_line_errors(t_mymlx *mymlx)
{
	if (!mymlx->map.map_str)
	{
		ft_printf("map is empty\n");
		 vree(mymlx);
		exit(1);
	}
	if (mymlx->map.map_str[0] == '\n')
	{
		ft_printf("empty lines in map \n");
		 vree(mymlx);
		exit(1);
	}
}

void	line_count(t_mymlx *mymlx)
{
	if (mymlx->map.map_line_counter != mymlx->map.num_rows)
	{
		ft_printf("error the map rows element are not correct \n");
		 vree(mymlx);
		exit(1);
		
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
			ft_printf("error the map col element are not correct !\n");
			vree(mymlx);
			exit(1);
		
		}
		i++;
	}
}
