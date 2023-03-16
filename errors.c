/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:22 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/16 16:58:02 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	newline(t_mymlx *mymlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mymlx->map.num_rows)
	{
		j = 0;
		while (j < mymlx->map.num_col)
		{
			if (mymlx->map.splited[0][j] == '\n')
				exit(0);
		}
		j++;
	}
	i++;
}

void	openber(int fd)
{
	if (fd == -1)
	{
		printf("open error");
		exit(0);
	}
}

void	line_errors(t_mymlx *mymlx)
{
	if (!mymlx->map.map_str)
	{
		printf("error map is empty\n");
		exit(0);
	}
	if (mymlx->map.map_str[0] == '\n')
	{
		printf("error too many newline \n");
		exit(0);
	}
}
