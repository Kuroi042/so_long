/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:55:57 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/29 02:40:07 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char *argv[])
{
	t_mymlx	*mymlx;
	int		fd;

	mymlx = (t_mymlx *)malloc(sizeof(t_mymlx));
	ft_memset(mymlx, 0, sizeof(t_mymlx));
	mymlx->map_str = ft_calloc(1, sizeof(char));
	free(mymlx->map_str);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		openber(fd, mymlx);
		berber(argv[1], mymlx);
		mymlx->map1 = (char *)malloc(1 * sizeof(char));
		mymlx->map_str = get_next_line(fd);
		new_line_errors(mymlx);
		get_and_join(mymlx, fd);
		rowsandcols(mymlx);
		allerror(mymlx);
		mlx(mymlx);
	}
	ft_printf("./a.out ??\n");
	mymlx = NULL;
	free(mymlx);
	exit(1);
}
