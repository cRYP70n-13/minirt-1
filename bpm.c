#include "bpm.h"
#include "bpm.h"

void write_bmp(char *filename, t_bmp rgb, int width, int height)
{
    char tag[] = {'B', 'M'};
    int header[] = {
        0, 0, 0x36, 0x28, width, height, 0x180001,
        0, 0, 0, 0, 0, 0};
    char *bitmap = (char*) rgb.pixels;
    int fd = open("bm1.bmp", O_CREAT | O_WRONLY, S_IRWXU);
    write(fd, &tag, sizeof(tag));
    write(fd, &header, sizeof(header));
    write(fd, &bitmap, sizeof(bitmap));
}

t_bmp create_pixels_array(int width, int height)
{
    t_bmp bmp;

    bmp.width = width;
    bmp.height = height;
    bmp.pixels = malloc(sizeof(uint32_t) * (width * height));
    return (bmp);
}


void set_bmp_pixel (int x, int y, t_trgb value)
{
    
}

int main()
{

    int width = 3;
    int height = 2;
    char tag[] = {'B', 'M'};
    int header[] = {
        0, 0, 0x36, 0x28, width, height, 0x180001,
        0, 0, 0, 0, 0, 0};
    char bitmap[] = {
        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x00, // Padding
        0x00, // Padding
        0x00, // Padding

        255, // Blue
        0,   // Green
        0,   // Red

        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x00, // Padding
        0x00, // Padding
        0x00, // Padding
        // 0x00, // Padding
    };
    int fd = open("bm1.bmp", O_CREAT | O_WRONLY, S_IRWXU);
    write(fd, &tag, sizeof(tag));
    write(fd, &header, sizeof(header));
    write(fd, &bitmap, sizeof(bitmap));
    printf("%lu", sizeof(tag));
    close(fd);
    return (0);
}
