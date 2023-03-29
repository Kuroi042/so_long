/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:22 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/29 02:37:48 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	openber(int fd, t_mymlx *mymlx)
{
	if (fd == -1)
	{
		ft_printf("open error");
		mymlx = NULL;
		free(mymlx);
		exit(1);
	}
}

void	new_line_errors(t_mymlx *mymlx)
{
	if (!mymlx->map_str)
	{
		ft_printf("map is empty\n");
		mymlx = NULL;
		free(mymlx);
		exit(1);
	}
	if (mymlx->map_str[0] == '\n')
	{
		ft_printf("empty lines in map \n");
		mymlx = NULL;
		free(mymlx);
		exit(1);
	}
}

void	line_count(t_mymlx *mymlx)
{
	if (mymlx->map_line_counter != mymlx->num_rows)
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
	while (i < mymlx->num_rows)
	{
		if (mymlx->num_col != len(mymlx->splited[i]))
		{
			ft_printf("error the map col element are not correct !\n");
			vree(mymlx);
			exit(1);
		}
		i++;
	}
}
