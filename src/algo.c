/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:58:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 17:16:49 by maegaspa    ###    #+. /#+    ###.fr     */
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
			if (cnt->map[cnt->x][cnt->y] == 1)
				cnt->heat[cnt->x][cnt->y] = 1;
			cnt->y++;
		}
		cnt->x++;
	}
	fill_heat(*size, *cnt);
	return (1);
}

void			fill_heat(t_size size, t_cnt cnt)
{
	int			i;

	i = -1;
	cnt_ini2(&cnt);
	size.mxy = size.mapy > size.mapx ? size.mapy : size.mapx;
	while (++i < size.mxy)
	{
		cnt.x = 0;
		while (cnt.x < size.mapx)
		{
			cnt.y = 0;
			while (cnt.y < size.mapy)
			{
				if (cnt.map[cnt.x][cnt.y] == 1)
					cnt.heat[cnt.x][cnt.y] = 1;
				if (cnt.x >= 0 && cnt.y >= 0 && cnt.x < size.mapx &&
					cnt.y < size.mapy && cnt.heat[cnt.x][cnt.y] == cnt.p - 1)
					place_heat(&cnt, &size);
				cnt.y++;
			}
			cnt.x++;
		}
		cnt.p++;
	}
}

void			place_heat(t_cnt *cnt, t_size *size)
{
	if (cnt->y - 1 >= 0 && cnt->heat[cnt->x][cnt->y - 1] == -1)
		cnt->heat[cnt->x][cnt->y - 1] = cnt->p;
	if (cnt->y + 1 < size->mapy && cnt->heat[cnt->x][cnt->y + 1] == -1)
		cnt->heat[cnt->x][cnt->y + 1] = cnt->p;
	if (cnt->y - 1 >= 0 && cnt->x - 1 >= 0 &&
		cnt->heat[cnt->x - 1][cnt->y - 1] == -1)
		cnt->heat[cnt->x - 1][cnt->y - 1] = cnt->p;
	if (cnt->x - 1 >= 0 && cnt->heat[cnt->x - 1][cnt->y] == -1)
		cnt->heat[cnt->x - 1][cnt->y] = cnt->p;
	if (cnt->y + 1 < size->mapy && cnt->x - 1 >= 0 &&
		cnt->heat[cnt->x - 1][cnt->y + 1] == -1)
		cnt->heat[cnt->x - 1][cnt->y + 1] = cnt->p;
	if (cnt->y - 1 >= 0 && cnt->x + 1 < size->mapx &&
		cnt->heat[cnt->x + 1][cnt->y - 1] == -1)
		cnt->heat[cnt->x + 1][cnt->y - 1] = cnt->p;
	if (cnt->x + 1 < size->mapx && cnt->heat[cnt->x + 1][cnt->y] == -1)
		cnt->heat[cnt->x + 1][cnt->y] = cnt->p;
	if (cnt->x + 1 < size->mapx && cnt->y + 1 < size->mapy
		&& cnt->heat[cnt->x + 1][cnt->y + 1] == -1)
		cnt->heat[cnt->x + 1][cnt->y + 1] = cnt->p;
}

void			multi_me(t_cnt *cnt, t_size *size)
{
	cnt->me = 0;
	cnt->mx = 0;
	cnt->en = 0;
	while (cnt->mx < size->x)
	{
		cnt->my = 0;
		while (cnt->my < size->y)
		{
			if (cnt->x + cnt->mx < size->mapx &&
				cnt->y + cnt->my < size->mapy &&
				size->shape[cnt->mx][cnt->my] == 1 &&
				cnt->map[cnt->x + cnt->mx][cnt->y + cnt->my] == -2)
				cnt->me++;
			if (cnt->x + cnt->mx < size->mapx &&
				cnt->y + cnt->my < size->mapy
				&& size->shape[cnt->mx][cnt->my] == 1 &&
				cnt->map[cnt->x + cnt->mx][cnt->y + cnt->my] == 1)
				cnt->en++;
			cnt->my++;
		}
		cnt->mx++;
	}
}
