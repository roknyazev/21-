#include "mlx/mlx.h"
#include "minirt.h"

int main()
{



	//void *mlx;
	//void *win;
	//int	i;
	//int	j;
	//mlx = mlx_init();
	//win = mlx_new_window(mlx, 1920 ,1080, "rt");
	//i = 0;
	//while (i < 1920)
	//{
	//	j = 0;
	//	while (j < 1080)
	//	{
	//		mlx_pixel_put(mlx, win, i, j, 0X00FFFF);
	//		j++;
	//	}
	//	i++;
	//}
	//mlx_loop(mlx);


	t_vector *color;

	color = vector(5.5, 3, 7);
	color->scalar_product(color, -5);
	printf("%f\n%f\n%f\n", color->x, color->y, color->z);
	free(color);

	return 0;
}
