#include "../includes/filler.h"


void	aff_map(t_size *size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size->x)
	{
		y = 0;
		while (y < size->y)
		{
			printf("%d ", size->shape[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("-------------\n");
}

void	aff_map2(t_size *size, t_cnt *cnt)
{
	int		x;
	int		y;

	x = 0;
	while (x < size->mapx)
	{
		y = 0;
		while (y < size->mapy)
		{
			printf("%d ", cnt->heat[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("-------------\n");
}

void	aff_map3(t_size *size, t_cnt *cnt)
{
	int		x;
	int		y;

	x = 0;
	while (x < size->mapx)
	{
		y = 0;
		while (y < size->mapy)
		{
			printf("%d ", cnt->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("-------------\n");
}