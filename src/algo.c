/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:58:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 16:43:42 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void				create_heat(t_cnt *cnt, t_size *size)
{
	cnt->x = 0;

	cnt->heat = malloc(sizeof(int *) * size->mapx);
	while (cnt->x < size->mapx)
	{
		cnt->y = 0;
		cnt->heat[cnt->x] = malloc(sizeof(int) * size->mapy + 1);
		while (cnt->y < size->mapy)
		{
			cnt->heat[cnt->x][cnt->y] = -1;
			if (cnt->heat[cnt->x][cnt->y] == cnt->heat[size->enemx][size->enemy])
				cnt->heat[cnt->x][cnt->y] = 1;
			if (cnt->heat[cnt->x][cnt->y] == cnt->heat[cnt->posx][cnt->posy])
				cnt->heat[cnt->x][cnt->y] = -2;
			cnt->y++;
		}
		cnt->x++;
	}
	fill_heat(*size, *cnt);
	free(cnt->heat);
}

void	aff_map(t_size *size, t_cnt *cnt)
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
}

void	fill_heat(t_size size, t_cnt cnt)
{
	int		i;

	i = -1;
	cnt_ini2(&cnt);
	size.mapy > size.mapx ? (size.mxy = size.mapy) : (size.mxy = size.mapx);
	/*size.mxy = size.mapx;
	if (size.mapy > size.mapx)
		size.mxy = size.mapy;*/
	while (++i < size.mxy)
	{
		while (cnt.x < size.mapx)
		{
			cnt.y = 0;
			while (cnt.y < size.mapy)
			{
				if (cnt.heat[cnt.x][cnt.y] == cnt.p - 1)
					place_heat(cnt);
				cnt.y++;
			}
			cnt.x++;
		}
		cnt.p++;
	}
}

void		place_heat(t_cnt cnt)
{
	if (cnt.heat[cnt.x][cnt.y - 1] == -1)
		cnt.heat[cnt.x][cnt.y - 1] = cnt.p;
	if (cnt.heat[cnt.x][cnt.y + 1] == -1)
		cnt.heat[cnt.x][cnt.y + 1] = cnt.p;
	if (cnt.heat[cnt.x - 1][cnt.y - 1] == -1)
		cnt.heat[cnt.x - 1][cnt.y - 1] = cnt.p;
	if (cnt.heat[cnt.x - 1][cnt.y] == -1)
		cnt.heat[cnt.x - 1][cnt.y] = cnt.p;
	if (cnt.heat[cnt.x - 1][cnt.y + 1] == -1)
		cnt.heat[cnt.x - 1][cnt.y + 1] = cnt.p;
	if (cnt.heat[cnt.x + 1][cnt.y - 1] == -1)
		cnt.heat[cnt.x + 1][cnt.y - 1] = cnt.p;
	if (cnt.heat[cnt.x + 1][cnt.y] == -1)
		cnt.heat[cnt.x + 1][cnt.y] = cnt.p;
	if (cnt.heat[cnt.x + 1][cnt.y + 1] == -1)
		cnt.heat[cnt.x + 1][cnt.y + 1] = cnt.p;
}
