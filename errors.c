/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:22 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/17 05:05:01 by mbouderr         ###   ########.fr       */
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
