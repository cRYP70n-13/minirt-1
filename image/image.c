#include "image.h"

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
