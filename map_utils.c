/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:13 by mbouderr          #+#    #+#             */
/*   Updated: 2023/04/01 23:02:12 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	get_and_join(t_mymlx *mymlx, int fd)
{	
	int zeb = 0;
	mymlx->map1 = (char *)malloc(sizeof(char) * 500000);
	mymlx->reader =  read(fd, mymlx->map1, 500000);
	if (mymlx->reader== 0)
	{
		ft_printf("map is empty\n");
		free(mymlx->map1);
		free(mymlx);
		exit(1);
	}
		
	mymlx->map_line_counter++;
	while (mymlx->map1[zeb])
	{
		if (mymlx->map1[zeb] == '\n')
			mymlx->map_line_counter++;
		if (mymlx->map1[zeb] == '\n' && mymlx->map1[zeb + 1] == '\n'){
			ft_printf("ZEB ERROR\n");
			free(mymlx->map1);
			free(mymlx);
			exit(1);	
		}
		zeb++;
	}	
}

void	rowsandcols(t_mymlx *mymlx)
{
	mymlx->maptester = ft_split(mymlx->map1, '\n');
	mymlx->splited = ft_split(mymlx->map1, '\n');
		free(mymlx->map1);

	while (mymlx->splited[mymlx->num_rows] != NULL)
	{
		mymlx->num_rows++;
	}
	mymlx->num_col = len(mymlx->splited[0]);
}

void	permetre(t_mymlx *mymlx)
{
	while (mymlx->r < mymlx->num_rows)
	{
		while (mymlx->c < mymlx->num_col)
		{
			if (mymlx->splited[0][mymlx->c] != '1')
				mymlx->check_tool_up = -1;
			if (mymlx->splited[mymlx->num_rows - 1][mymlx->c] != '1')
				mymlx->check_tool_teht = -1;
			mymlx->c++;
		}
		if (mymlx->splited[mymlx->r][0] != '1')
			mymlx->check_side_left = -1;
		if (mymlx->splited[mymlx->r][mymlx->num_col - 1] != '1')
		mymlx->check_side_right = -1;
		mymlx->r++;
	}
	if (mymlx->check_tool_up != 0 || mymlx->check_tool_teht != 0
		|| mymlx->check_side_left != 0 || mymlx->check_side_right != 0)
	{
		ft_printf("error map check the map 'wall' perimettre\n");
		vree(mymlx);
		exit(1);
	}
}

void	coin_counter(int i, int j, char **splited, t_mymlx *mymlx)
{
	if (splited[i][j] == 'C')
	{
		mymlx->coincounter += 1;
		splited[i][j] = '0';
	}
	if (mymlx->num_coins == mymlx->coincounter)
		mymlx->coin_yes = 1;
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
