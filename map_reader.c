/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:55:57 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/20 17:55:46 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
// void freee(t_mymlx *mymlx){
// 	free(mymlx->map.map_str);
// 	free(mymlx->map.map1);
// 	free(mymlx->map.splited);
// 	free(mymlx->map.maptester);
// 	free(mymlx);
// }
int	main(int argc, char *argv[])
{
	t_mymlx	*mymlx;
	int		fd;

	mymlx = (t_mymlx *)malloc(sizeof(t_mymlx));
	ft_memset(mymlx, 0, sizeof(t_mymlx));
	mymlx->map.map_str = ft_calloc(1,1);
	free(mymlx->map.map_str);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		openber(fd);
		berber(argv[1]);
			mymlx->map.map1 = (char *)malloc(1 * sizeof(char));
			mymlx->map.map_str = get_next_line(fd);
		N_line_errors(mymlx);
		get_and_join(mymlx, fd);
		rowsandcols(mymlx);	
		allerror(mymlx);
		mlx(mymlx);
	}
	ft_printf("./a.out ??\n");
	exit(1);
}
