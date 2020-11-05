#include "image.h"

t_trgb  create_pixel(int t, int r, int g, int b)
{
	return (t << 24 | (r << 16) | (g << 8) | b);
}

/*
**  getting transparency, red, green, blue out of t_trgb 
*/
int	get_t (int t_trgb)
{
	return (t_trgb >> 24);
}

int	get_r(int t_trgb)
{
	return (t_trgb >> 16);
}

int	get_g(int t_trgb)
{
	return (t_trgb >> 8 & 0xff);
}

int	get_b(int t_trgb)
{
	return (t_trgb & 0xFF);
}

t_image *mlx_create_img(void *mlx_ptr, int width, int height)
{
    t_image *img;
    int i;

    i = 0;
    if ((img = malloc(sizeof(struct s_image))) == NULL)
        return NULL;
    img->height = height;
    img->width = width;
    img->mlx_ptr = mlx_ptr;
    img->mlx_img = mlx_new_image(mlx_ptr, width, height);
    img->data = mlx_get_data_addr(img->mlx_img, &img->bits_per_pixel, &img->size_line, &img->endian);
    return (img);
}

void mlx_img_destroy(t_image *img)
{
    mlx_destroy_image(img->mlx_ptr, img->mlx_img);
    free(img);
}

void img_set_pixel(t_image *img, int x, int y, t_trgb value)
{
    char *tar;

    tar = img->data + y * img->size_line + x * (img->bits_per_pixel / 8);
    *(int*)tar = value;
}
