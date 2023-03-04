
#include "solong.h"
t_mymlx mymlx;
int main(void)
{
	void *mlx;
	void *mlx_win;
	int width = (32 * mymlx.map->num_col);
	int height = (32 * mymlx.map->num_rows);

	
	mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, width, height, "jojo");

	mymlx.wall = mlx_xpm_file_to_image(mlx, "waaall.xpm", &width, &height);
	mymlx.joseph = mlx_xpm_file_to_image(mlx, "jooseph.xpm", &width, &height);
	mymlx.sand = mlx_xpm_file_to_image(mlx, "sand.xpm", &width, &height);
	mymlx.coin = mlx_xpm_file_to_image(mlx, "bassit.xpm", &width, &height);
	mymlx.exit = mlx_xpm_file_to_image(mlx, "portal.xpm", &width, &height);



	 mapdrwing(mymlx.map->num_rows, mymlx.map->num_col , mymlx.map->splited,mlx,mlx_win);

	mlx_loop(mlx);
}