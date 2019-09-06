/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:58:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 18:18:29 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				create_heat(t_cnt *cnt, t_size *size)
{
	cnt->x = 0;
	if (!(cnt->heat = malloc(sizeof(int *) * size->mapx)))
		return (0);
	while (cnt->x < size->mapx)
	{
		cnt->y = 0;
		if (!(cnt->heat[cnt->x] = malloc(sizeof(int) * size->mapy)))
			return (0);
		while (cnt->y < size->mapy)
		{
			cnt->heat[cnt->x][cnt->y] = -1;
			if (cnt->x == size->enemx && cnt->y == size->enemy)
				cnt->heat[cnt->x][cnt->y] = 1;
			if (cnt->x == cnt->posx && cnt->y == cnt->posy)
				cnt->heat[cnt->x][cnt->y] = -2;
			cnt->y++;
		}
		cnt->x++;
	}
	fill_heat(*size, *cnt);
	return (1);
}

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

void	fill_heat(t_size size, t_cnt cnt)
{
	int		i;

	i = -1;
	cnt_ini2(&cnt);
	size.mapy > size.mapx ? (size.mxy = size.mapy) : (size.mxy = size.mapx);
	while (++i < size.mxy)
	{
		cnt.x = 0;
		while (cnt.x < size.mapx)
		{
			cnt.y = 0;
			while (cnt.y < size.mapy)
			{
				if (cnt.heat[cnt.x][cnt.y] == cnt.p - 1 && cnt.x > 0
					&& cnt.y > 0 && cnt.x < size.mapx && cnt.y < size.mapy)
					place_heat(&cnt, &size);
				cnt.y++;
			}
			cnt.x++;
		}
		cnt.p++;
	}
}

void		place_heat(t_cnt *cnt, t_size *size)
{
	if (cnt->heat[cnt->x][cnt->y - 1] == -1)
		cnt->heat[cnt->x][cnt->y - 1] = cnt->p;
	if (cnt->heat[cnt->x][cnt->y + 1] == -1)
		cnt->heat[cnt->x][cnt->y + 1] = cnt->p;
	if (cnt->heat[cnt->x - 1][cnt->y - 1] == -1)
		cnt->heat[cnt->x - 1][cnt->y - 1] = cnt->p;
	if (cnt->x - 1 > 0 && cnt->heat[cnt->x - 1][cnt->y] == -1)
		cnt->heat[cnt->x - 1][cnt->y] = cnt->p;
	if (cnt->y < size->mapy && cnt->heat[cnt->x - 1][cnt->y + 1] == -1)
		cnt->heat[cnt->x - 1][cnt->y + 1] = cnt->p;
	if (cnt->x + 1 < size->mapx && cnt->y - 1 < size->mapy
		&& cnt->heat[cnt->x + 1][cnt->y - 1] == -1)
		cnt->heat[cnt->x + 1][cnt->y - 1] = cnt->p;
	if (cnt->x + 1 < size->mapx && cnt->y < size->mapy
		&& cnt->heat[cnt->x + 1][cnt->y] == -1)
		cnt->heat[cnt->x + 1][cnt->y] = cnt->p;
	if (cnt->x + 1 < size->mapx && cnt->y + 1 < size->mapy
		&& cnt->heat[cnt->x + 1][cnt->y + 1] == -1)
		cnt->heat[cnt->x + 1][cnt->y + 1] = cnt->p;
}
