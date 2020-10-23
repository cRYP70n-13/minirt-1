#include "canvas.h"

/*
** a trgb is just an int that we can store in every
** one of their bytes the transperncy, red
** , green and blue percentage using bitshifting
*/

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

/*
**  fill the whole canvas with one pixel
*/
void	canvas_fill(t_canvas *A, t_trgb bg)
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
			A->pixel[i][j] = bg;
			j++;
		}
		i++;
	}
}

/*
** the constructor for the canvas
*/

t_canvas	*canvas_create(int w, int h, t_trgb bg)
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

// I think we can just remove this hole function it does nothing
t_canvas	*canvas(int w, int h)
{
	return (canvas_create(w, h, 0));
}

/*
** canvas destructor
*/

void	canvas_destroy(t_canvas *A)
{
	free(A->data);
	free(A->pixel);
	free(A);
}

/*
**  get a specified pixel from a canvas
*/
t_trgb	canvas_get(t_canvas *A, int x, int y)
{
	return (A->pixel[y][x]);
}

/*
** modify a specified pixel
*/

void	set_pixel(t_canvas *A, int x, int y, t_trgb value)
{
	A->pixel[y][x] = value;
}

