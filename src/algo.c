/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:58:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/27 17:49:27 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				algo(t_cnt *cnt, t_size *size, char *line)
{
	int			**heat;

	if (!(heat = malloc(sizeof(int *) * size->mapx)))
		return (0);
	while (cnt->x < size->mapx)
	{
		cnt.y = 0;
		if (!(heat[x] = malloc(sizeof(int) * size->mapy)))
			return (0);
		while (cnt->y < size->mapy)
		{
			heat[cnt->x][cnt->y] = -2
			cnt->y++;
		}
		cnt->x++;
	}
	heat[size->enem_x][size->enem_y] = -1;
}

void	heatmap(int fd, t_size *size, t_cnt *cnt)
{
	int		i;
	int		k;
	int		co_x;
	int		co_y;
	int		tmp;

	tmp = size->mapx;
	if (size->mapy > size->mapx)
		tmp = size->mapy;
	co_x = size->enem_x;
	co_y = size->enem_y;
	cnt->x = 0;
	cnt->k = 0;
	while (tmp)
	{
		cnt->x = 0;
		while (cnt->x < size->mapx)
		{
			cnt->y = 0;
			while (cnt->y < size->mapy)
			{
				if ((heat[cnt->x][cnt->y] == cnt->k - 1) && (cnt->x - 1 >= 0 && cnt->y - 1 >= 0 && cnt->x + 1 < size->mapy && cnt->y + 1 < size->mapx))
				{
					if (heat[cnt->x - 1][cnt->y - 1] == -2)
						heat[cnt->x - 1][cnt->y - 1] = cnt->k;
					if (heat[cnt->x - 1][cnt->y] == -2)
						heat[cnt->x - 1][cnt->y] = cnt->k;
					if (heat[cnt->x - 1][cnt->y + 1] == -2)
						heat[cnt->x - 1][cnt->y + 1] = cnt->k;
					if (heat[cnt->x][cnt->y - 1] == -2)
						heat[cnt->x][cnt->y - 1] = cnt->k;
					if (heat[cnt->x][cnt->y + 1] == -2)
						heat[cnt->x][cnt->y + 1] = cnt->k;
					if (heat[cnt->x + 1][cnt->y - 1] == -2)
						heat[cnt->x + 1][cnt->y - 1] = cnt->k;
					if (heat[cnt->x + 1][icnt->y] == -2)
						heat[cnt->x + 1][icnt->y] = cnt->k;
					if (heat[cnt->x + 1][cnt->y + 1] == -2)
						heat[cnt->x + 1][cnt->y + 1] = cnt->k;
				}
				cnt->y++;
			}
			cnt->x++;
		}
		cnt->k++;
		tmp--;
	}
}