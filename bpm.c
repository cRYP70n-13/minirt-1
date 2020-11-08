#include "bpm.h"
#include "bpm.h"


void write_bmp (char *filename, char *rgb, int width, int height)
{
    char tag[2];
    int header[13];
    int padding;
    char *bitmap;

    padding = 0;
    if (((width * 3) % 4) != 0)
        padding = width;
    bitmap = malloc (sizeof(char) * ((width * height) + padding));
}

int main()
{

    int width = 4;
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

        0x35, // Blue
        0x41, // Green
        0xef, // Red


        255, // Blue
        0, // Green
        0, // Red

        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x35, // Blue
        0x41, // Green
        0xef, // Red

        0x35, // Blue
        0x41, // Green
        0xef // Red

        // 0x00, // Padding
        // 0x00, // Padding
        // 0x00,  // Padding
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