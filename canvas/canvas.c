#include "canvas.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | (r << 16) | (g << 8) | b);
}

int get_t (int t_trgb)
{
	return (t_trgb >> 24);
}

int get_r(int t_trgb)
{
	return (t_trgb >> 16);
}

int get_g(int t_trgb)
{
	return (t_trgb >> 8 & 0xff);
}

int get_b(int t_trgb)
{
	return (t_trgb & 0xFF);
}

void canvas_fill(t_canvas *A, t_trgb bg)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (i < A->h)
	{
		j = 0;
		while (j < A->w)
		{
			// write_pixel (A, j, i, bg);
			A->pixel[i][j] = bg;
			//printf ("%d %d %d %d\n",get_t(bg) ,get_r(bg), get_g(bg), get_b(bg));
			j++;
		}
		i++;
	}
}

t_canvas *canvas_create(int w, int h, t_trgb bg)
{
	t_canvas *A;
	int i;

	i = 0;
	if (!(A = malloc(sizeof(struct s_canvas))))
		return NULL;
	A->w = w;
	A->h = h;
	A->bg = bg;
	if (!(A->data = malloc(sizeof(int) * w * h)))
		return NULL;
	if (!(A->pixel = malloc (A->h * sizeof(int*))))
		return NULL;
	while (i < A->h)
	{
		A->pixel[i] = A->data + A->w * i;
		i++;
	}
	canvas_fill(A, bg);
	return (A);
}

void canvas_destroy(t_canvas *A)
{
	free(A->data);
	free(A->pixel);
	free(A);
}

t_trgb canvas_get(t_canvas *A, int x, int y)
{
	return (A->pixel[y][x]);
}


t_canvas *canvas(int w, int h)
{
	return (canvas_create(w, h, 0));
}

void write_pixel(t_canvas *A, int x, int y, t_trgb value)
{
	// t_trgb *ptr;
	// ptr = A->data + y * A->w + x;
	// *ptr = value;
	A->pixel[y][x] = value;
}

void write_pixel_center(t_canvas *A, int x, int y, t_trgb value)
{
	x = (A->w / 2) + x;
	y = (A->w / 2) + (y * -1);
	write_pixel(A, x, y, value);
}