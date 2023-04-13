#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_circle {
	char	c;
	float	x;
	float	y;
	float	radius;
	char	color;
}			t_circle;

typedef struct s_background {
	int	width;
	int	height;
	char	*bg;
}			t_background;

int	print_err(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

int	setting_background(FILE *file, t_background *background)
{
	int i;
	int result;
	char	c;

	result = fscanf(file, "%d %d %c\n", &background->width, &background->height, &c);
	if (result != 3)
		return (1);
	if (background->width <= 0 || background->width > 300 || background->height <= 0 || background->height > 300)
	   return (1);
	background->bg = (char *)malloc(sizeof(char) * (background->width * background->height));
	if (!background->bg)
		return (1);
	i = 0;
	while (i < background->width * background->height)
	{
		background->bg[i] = c;
		i++;
	}
	return (0);
}	

int	is_draw(float x, float y, t_circle *circle)
{
	float	distance;

	distance = sqrtf(powf(x - circle->x, 2.) + powf(y - circle->y, 2.));
	if (distance <= circle->radius)
	{
		if (circle->radius - distance < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void	draw_circle(t_circle *circle, t_background *background)
{
	int	x;
	int	y;
	int	result;
	
	y = 0;
	while (y < background->height)
	{
		x = 0;
		while (x < background->width)
		{
			result = is_draw((float)x, (float)y, circle);
			if ((result == 2 && circle->c == 'c') || (result && circle->c == 'C'))
				background->bg[y * background->width + x] = circle->color;
			x++;
		}
		y++;
	}
}

int	drawing(FILE *file, t_background *background)
{
	int	result;
	t_circle	circle;

	result = fscanf(file, "%c %f %f %f %c\n", &circle.c, &circle.x, &circle.y, &circle.radius, &circle.color);
	while (result == 5)
	{
		if ((circle.c != 'c' && circle.c != 'C') || circle.radius <= 0)
			return (1);
		draw_circle(&circle, background);
		result = fscanf(file, "%c %f %f %f %c\n", &circle.c, &circle.x, &circle.y, &circle.radius, &circle.color);
	}
	if (result != -1)
		return (1);
	return (0);
}

void	painting(t_background *background)
{
	int	i, j;

	i = 0;
	while (i < background->height)
	{
		j = 0;
		while (j < background->width)
		{
			write(1, &background->bg[i * background->width + j], 1);
			j++;
		}
		write(1,"\n", 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_background	 background;
	FILE	*file;

	if (argc != 2)
		return (print_err("argument"));
	file = fopen(argv[1], "r");
	if (!file)
		return (print_err("Operation file corrupted"));
	if (setting_background(file, &background))
		return (print_err("Operation file corrupted"));
	if (drawing(file, &background))
		return (print_err("Operation file corrupted"));
	painting(&background);
	if (file)
		fclose(file);
	return (0);
}
	
