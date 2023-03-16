/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:55:57 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/16 19:51:14 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
		berber(argv[1]);
		get_and_join(mymlx, fd);
		line_errors(mymlx);
		rowsandcols(mymlx);
		allerror(mymlx);
		mlx(mymlx);
	}
	printf("./a.out ??\n");
	exit(0);
}
