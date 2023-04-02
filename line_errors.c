/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:39:22 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/02 00:21:04 by mbouderr         ###   ########.fr       */
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
