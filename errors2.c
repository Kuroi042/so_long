/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:03 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/29 02:24:10 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	berber(char *str, t_mymlx *mymlx)
{
	if (!ft_strnstr(str, ".ber", ft_strlen(str)))
	{
		ft_printf(".ber is not found\n");
		mymlx = NULL;
		free(mymlx);
		exit(1);
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
	while (k < mymlx->num_rows)
	{
		while (j < mymlx->num_col)
		{
			if (mymlx->splited[k][j] == 'E')
				mymlx->exitcollected++;
			if (mymlx->splited[k][j] == 'P')
				mymlx->playercollected++;
			if (mymlx->splited[k][j] == 'C')
				mymlx->collcollected++;
			j++;
		}
		j = 0;
		k++;
	}
	if (mymlx->collcollected == 0 || mymlx->playercollected != 1
		|| mymlx->exitcollected != 1)
	{
		ft_printf("error Check 'E' 'P' 'C' in the map\n");
		vree(mymlx);
		exit(1);
	}
}
