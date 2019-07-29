/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:58:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 05:27:15 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				**create_heat(t_cnt *cnt, t_size *size)
{
	int			**heat;

	cnt->x = 0;
	if (!(heat = malloc(sizeof(int *) * size->mapx)))
		return (0);
	while (cnt->x < size->mapx)
	{
		cnt->y = 0;
		if (!(heat[cnt->x] = malloc(sizeof(int) * size->mapy)))
			return (0);
		while (cnt->y < size->mapy)
			heat[cnt->x][cnt->y++] = -1;
		cnt->x++;
	}
	heat[size->posx][size->posy] = -2;
	heat[size->enemx][size->enemy] = 0;
	fill_heat(&size, &cnt, heat);
	return (heat);
}

void	fill_heat(t_size *size, t_cnt *cnt, int **heat)
{
	int		i;

	i = -1;
	cnt_ini2(&cnt);
	size->mxy = size->mapx;
	if (size->mapy > size->mapx)
		size->mxy = size->mapy;
	while (++i < size->mxy)
	{
		while (cnt->x < size->mapx)
		{
			cnt->y = 0;
			while (cnt->y < size->mapy)
			{
				if ((heat[cnt->x][cnt->y] == cnt->p - 1))
					place_heat(heat, &cnt);
				cnt->y++;
			}
			cnt->x++;
		}
		cnt->p++;
	}
}

void		place_heat(int	**heat, t_cnt *cnt)
{
	if (heat[cnt->x][cnt->y - 1] == -1)
		heat[cnt->x][cnt->y - 1] = cnt->p;
	if (heat[cnt->x][cnt->y + 1] == -1)
		heat[cnt->x][cnt->y + 1] = cnt->p;
	if (heat[cnt->x - 1][cnt->y - 1] == -1)
		heat[cnt->x - 1][cnt->y - 1] = cnt->p;
	if (heat[cnt->x - 1][cnt->y] == -1)
		heat[cnt->x - 1][cnt->y] = cnt->p;
	if (heat[cnt->x - 1][cnt->y + 1] == -1)
		heat[cnt->x - 1][cnt->y + 1] = cnt->p;
	if (heat[cnt->x + 1][cnt->y - 1] == -1)
		heat[cnt->x + 1][cnt->y - 1] = cnt->p;
	if (heat[cnt->x + 1][cnt->y] == -1)
		heat[cnt->x + 1][cnt->y] = cnt->p;
	if (heat[cnt->x + 1][cnt->y + 1] == -1)
		heat[cnt->x + 1][cnt->y + 1] = cnt->p;
}