/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permettre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:13 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/19 00:56:23 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	get_and_join(t_mymlx *mymlx, int fd)
{
	while (1)
	{
		mymlx->map.map1 = ft_strjoinget(mymlx->map.map1, mymlx->map.map_str);
		mymlx->map.map_line_counter++;
		mymlx->map.map_str = get_next_line(fd);
		if (mymlx->map.map_str == NULL)
			break ;
	}
}

void	rowsandcols(t_mymlx *mymlx)
{
	mymlx->map.maptester = ft_split(mymlx->map.map1, '\n');
	mymlx->map.splited = ft_split(mymlx->map.map1, '\n');
	while (mymlx->map.splited[mymlx->map.num_rows] != NULL)
	{
		mymlx->map.num_rows++;
	}
	mymlx->map.num_col = len(mymlx->map.splited[0]);

	int i =0;
	int j=0;
	while(i<mymlx->map.num_rows){
		while(j < mymlx->map.num_col){
				free(mymlx->map.splited[0]);
				j++;
		}
		i++;
	}
}



void	permetre(t_mymlx *mymlx)
{
	while (mymlx->map.r < mymlx->map.num_rows)
	{
		while (mymlx->map.c < mymlx->map.num_col)
		{
			if (mymlx->map.splited[0][mymlx->map.c] != '1')
				mymlx->map.check_tool_up = -1;
			if (mymlx->map.splited[mymlx->map.num_rows
					- 1][mymlx->map.c] != '1')
				mymlx->map.check_tool_teht = -1;
			mymlx->map.c++;
		}
		if (mymlx->map.splited[mymlx->map.r][0] != '1')
		mymlx->map.check_side_left = -1;
		if (mymlx->map.splited[mymlx->map.r][mymlx->map.num_col - 1] != '1')
			mymlx->map.check_side_right = -1;
		mymlx->map.r++;
	}
	if (mymlx->map.check_tool_up != 0 || mymlx->map.check_tool_teht != 0
		|| mymlx->map.check_side_left != 0 || mymlx->map.check_side_right != 0)
	{
		ft_printf("error map check the map 'wall' perimettre\n");
		exit(0);
	}
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i]!= '\0')
	{
		i++;
	}
	return (i);
}
