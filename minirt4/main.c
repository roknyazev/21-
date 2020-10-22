#include "minirt.h"
#include "mlx.h"

int main(int argc, char *argv[])
{
	t_scene		*scene;
	t_canvas	*canvas;
	void *mlx;
	void *win;
	int	i;
	int	j;
	int c;
	int camera_index;

	camera_index = 0;
	if (!(scene = new_scene("../scene.rt")))
		exit(1);
	if (!(canvas = render(scene, camera_index)))
		exit(1);
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
	return (0);
}
