#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,12*32 ,  5*32, "jojo");
	
	mlx_loop(mlx);
}