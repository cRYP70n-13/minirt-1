#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"

int main()
{
	void *mlx_ptr;
	void *mlx_window;
	t_canvas *c;
	int i;
	int j;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 1000, 1000, "first visualalisation");
	c = canvas_create(1000, 1000, 0);
	i = 0;
	j = 0;


	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			set_pixel(c, j, i, create_pixel(0, 255.999 * (i/1000.0), 255.99 * (j/1000.0), 0));
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			mlx_pixel_put(mlx_ptr, mlx_window, j, i, canvas_get(c, j, i));
			j++;
		}
		i++;
	}

	//  write_pixel(c, 499, 499, create_trgb(0, 255, 0, 0));
	//write_pixel(c, 499, 499, create_trgb(0, 255, 0, 0));
	//mlx_pixel_put(mlx_ptr, mlx_window, 250, 250, canvas_get(c, 250, 250));
	// mlx_pixel_put(mlx_ptr, mlx_window, 499, 499, canvas_get(c, 499, 499));
	//write_pixel (c, 100, 100, create_trgb(0, 255, 255, 0));
	//t_trgb col = canvas_get(c, 100, 100);
	//printf("%d %d %d %d\n",get_t(col) ,get_r(col), get_g(col), get_b(col));
	mlx_loop(mlx_ptr);
	//t_trgb test = create_trgb (, 255, 0, 0);
	//printf ("%d", get_t(test));
	mlx_destroy_window(mlx_ptr, mlx_window);
	canvas_destroy(c);
	return (0);
}