
#include "solong.h"
t_mymlx mymlx;
t_mymap mymap;
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
 
	// mymlx.tool = 32*mymap.num_col;
	// mymlx.ard =	32*&mymap.num_rows; 

		mymlx.wall = mlx_xpm_file_to_image(mlx, "waaall.xpm", 32* mymlx.tool, 32* mymlx.ard);
mymlx.joseph = mlx_xpm_file_to_image(mlx, "jooseph.xpm", 32*mymlx.tool, 32*mymlx.ard);
mymlx.sand = mlx_xpm_file_to_image(mlx, "sand.xpm", 32*mymlx.tool, 32*mymlx.ard);
mymlx.coin = mlx_xpm_file_to_image(mlx, "bassit.xpm", 32*mymlx.tool, 32*mymlx.ard);
mymlx.exit = mlx_xpm_file_to_image(mlx, "portal.xpm", 32*mymlx.tool, 32*mymlx.ard);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,12*32 ,  5*32, "jojo");
	 mapdrwing(mymap.num_rows, mymap.num_col , mymap.splited,mlx,mlx_win);

	
	mlx_loop(mlx);
}