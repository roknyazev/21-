#include "mlx/mlx.h"
#include "minirt.h"

int main()
{
	t_scene		*scene;
	t_canvas	*canvas;
	void *mlx;
	void *win;
	int	i;
	int	j;
	int c;

	scene = new_scene("scene.rt");
	canvas = render(scene, 0);

	mlx = mlx_init();
	win = mlx_new_window(mlx, scene->resolution_x ,scene->resolution_y, "rt");
	i = 0;
	while (i < scene->resolution_x)
	{
		j = 0;
		while (j < scene->resolution_y)
		{
			c = canvas->get_pixel(canvas, i, j)->in_hex(canvas->get_pixel(canvas, i, j));
			mlx_pixel_put(mlx, win, i, j, c);
			j++;
		}
		i++;
	}
	canvas->destroy(canvas);
	scene->destroy(scene);
	mlx_loop(mlx);
	return 0;
}
