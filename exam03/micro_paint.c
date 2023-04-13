#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_zone {
	int	width;
	int	height;
	char	*map;
}	t_zone;

typedef struct s_rectangle {
	char	c;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}	t_rectangle;

int	print_err(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

int	setting_zone(FILE *file, t_zone *zone)
{
	int	result;
	int	i;
	char	c;

	result = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &c);
	if (result != 3)
		return (1);
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return (1);
	zone->map = (char *)malloc(sizeof(char) * (zone->width * zone->height));
	if (!zone->map)
		return (1);
	i = 0;
	while (i < zone->width * zone->height)
	{
		zone->map[i] = c;
		i++;
	}
	return (0);
}

int	paint_rect(float x, float y, t_rectangle *rect)
{
	if (x < rect->x || rect->width + rect->x < x || y < rect->y || rect->y + rect->height < y)
		return (0);
	if (x - rect->x < 1.00000000 || rect->width + rect->x - x < 1.00000000 || y - rect->y < 1.00000000 || rect->y + rect->height - y < 1.00000000)
		return (2);
	return (1);
}

void	draw_rect(t_rectangle *rect, t_zone *zone)
{
	int	x;
	int	y;
	int	is_in;

	y = 0;
	while (y < zone->height)
	{
		x = 0;
		while (x < zone->width)
		{
			is_in = paint_rect((float)x, (float)y, rect);
			if ((is_in == 2 && rect->c == 'r') || (is_in && rect->c == 'R'))
				zone->map[y * zone->width + x] = rect->color;
			x++;
		}
		y++;
	}
}	

int	drawing(FILE *file, t_zone *zone)
{
	int	result;
	t_rectangle	rect;

	result = fscanf(file, "%c %f %f %f %f %c\n", &rect.c, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
	while (result == 6)
	{
		if (rect.c != 'r' && rect.c != 'R')
			return (1);
		if (rect.width <= 0.00000000 || rect.height <= 0.00000000)
			return (1);
		draw_rect(&rect, zone);
		result = fscanf(file, "%c %f %f %f %f %c\n", &rect.c, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
	}
	if (result != -1)
		return (1);
	return (0);
}

void	painting(t_zone *zone)
{
	int	i;
	int	j;

	i = 0;
	while (i < zone->height)
	{
		j = 0;
		while (j < zone->width)
		{
			printf("%c", zone->map[i * zone->width + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}	

int main(int argc, char *argv[])
{
	t_zone	zone;
	FILE *file;

	if (argc != 2)
		return (print_err("argument"));
	file = fopen(argv[1], "r");
	if (!file)
		return (print_err("Operation file corrupted"));
	if (setting_zone(file, &zone))
		return (print_err("Operation file corrupted"));
	if (drawing(file, &zone))
		return (print_err("Operation file corrupted"));
	painting(&zone);
	if (file)
		fclose(file);
	return (0);
}
