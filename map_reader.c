/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:55:57 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/17 06:54:49 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
void freee(t_mymlx *mymlx){
	free(mymlx->map.map_str);
	free(mymlx->map.map1);
	free(mymlx);
	
}
int	main(int argc, char *argv[])
{
	t_mymlx	*mymlx;
	int		fd;

	mymlx = (t_mymlx *)malloc(sizeof(t_mymlx));
	ft_memset(mymlx, 0, sizeof(t_mymlx));
	mymlx->map.map_str = malloc(1);
	if (!mymlx->map.map_str)
		return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		openber(fd);
			mymlx->map.map1 = (char *)malloc(1 * sizeof(char));
	mymlx->map.map_str = get_next_line(fd);
		line_errors(mymlx);
		get_and_join(mymlx, fd);
		rowsandcols(mymlx);
		allerror(mymlx);
		
		mlx(mymlx);
		while(1){
			
		}
	}
	printf("./a.out ??\n");
	exit(0);
}
