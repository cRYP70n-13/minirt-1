#include "bmp.h"
#include "bmp.h"
#include <string.h>

// Function to round an int to a multiple of 4
int round4(int x)
{
    return x % 4 == 0 ? x : x - x % 4 + 4;
}

void write_bmp(char *filename, t_bmp rgb, int width, int height)
{
    // Pad the width of the destination to a multiple of 4
    int padded_width = round4(width * 3);

    char tag[] = {'B', 'M'};
    int header[] = {
        0, 0, 0x36, 0x28, width, height, 0x180001,
        0, 0, 0, 0, 0, 0};
    char *bitmap = (char *)rgb.pixels;
    // char bitmap[] = {
    // 255, // Blue
    // 0,   // Green
    // 0,   // Red
    // 0};

    int fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
    write(fd, &tag, sizeof(tag));
    write(fd, &header, sizeof(header));
    write(fd, rgb.pixels, rgb.bitmap_size);
    printf("%lu", rgb.bitmap_size);
    // write(fd, &nz, 1);
    // write(fd, &nz, 1);
    // write(fd, &nz, 1);

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

    b = get_b(value);
    g = get_g(value);
    r = get_r(value);
    bmp->pixels[y + bmp->padded_width + x * 3 + 0] = b;
    bmp->pixels[y + bmp->padded_width + x * 3 + 1] = g;
    bmp->pixels[y + bmp->padded_width + x * 3 + 2] = r;
}

void write_bmp1(char *filename, int length, int width) {
    int height = (length / 3) / width;

    // Pad the width of the destination to a multiple of 4
    int padded_width = round4(width * 3);
    
    int bitmap_size = height * padded_width * 3;
    char *bitmap = (char *) malloc(bitmap_size * sizeof(char));
    for (int i = 0; i < bitmap_size; i++) bitmap[i] = 0;

    // For each pixel in the RGB image...
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            
            // For R, G, and B...
            for (int color = 0; color < 3; color++) {

                // Get the index of the destination image
                int index = row * padded_width + col * 3 + color;

                // Set the destination to the value of the src at row, col.
                bitmap[index] = 255;
            }
        }
    }

    char tag[] = { 'B', 'M' };
    int header[] = {
        0, 0, 0x36, 0x28, width, height, 0x180001, 
        0, 0, 0x002e23, 0x002e23, 0, 0
    };
    header[0] = sizeof(tag) + sizeof(header) + bitmap_size;
    FILE *fp = fopen(filename, "w+");
    fwrite(&tag, sizeof(tag), 1, fp);
    fwrite(&header, sizeof(header), 1, fp);
    fwrite(bitmap, bitmap_size * sizeof(char), 1, fp);
    fclose(fp);
    free(bitmap);
}