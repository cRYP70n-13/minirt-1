#include "bmp.h"
#include "bmp.h"
#include <string.h>

// Function to round an int to a multiple of 4
int round4(int x)
{
    return x % 4 == 0 ? x : x - x % 4 + 4;
}

void write_bmp(char *filename, t_bmp *rgb)
{
    char tag[2];
    int header[] = {
        0, 0, 0x36, 0x28, rgb->width, rgb->height, 0x180001,
        0, 0, 0, 0, 0, 0};
    header[0] = sizeof(tag) + sizeof(header) + rgb->bitmap_size;
    int fd;


    tag[0] = 'B';
    tag[1] = 'M';
    header[0] = sizeof(tag) + sizeof(header) + rgb->bitmap_size;
    fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
    write(fd, &tag, sizeof(tag));
    write(fd, &header, sizeof(header));
    write(fd, rgb->pixels, rgb->bitmap_size);
    close(fd);
}

t_bmp create_pixels_array(int width, int height)
{
    t_bmp bmp;
    int i;

    bmp.width = width;
    bmp.height = height;
    bmp.padded_width = round4(width * 3);
    bmp.bitmap_size = height * bmp.padded_width * 3;
    bmp.pixels = malloc(bmp.bitmap_size);
    while (i < bmp.bitmap_size)
    {
        bmp.pixels[i] = 0;
        i++;
    }
    return (bmp);
}

void set_bmp_pixel(t_bmp *bmp, int x, int y, t_trgb value)
{
    t_imgcmp b;
    t_imgcmp g;
    t_imgcmp r;
    uint32_t *tar;
    int yr;

    b = get_b(value);
    g = get_g(value);
    r = get_r(value);
    yr = -y;
    int index = y * bmp->padded_width + x * 3 + 0;
    bmp->pixels[index] = (char)b;
    index = y * bmp->padded_width + x * 3 + 1;
    bmp->pixels[index] = (char)g;
    index = y * bmp->padded_width + x * 3 + 2;
    bmp->pixels[index] = (char)r;
}