/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:07:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 17:03:46 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void					is_placeable(t_cnt *cnt, t_size *size)
{
	cnt->x = 0;
	cnt->m = 0;
	cnt->tmp = 100000;
	while (cnt->x < size->mapx)
	{
		cnt->y = 0;
		while (cnt->y < size->mapy)
		{
			if (cnt->heat[cnt->x][cnt->y] != 1)
			{
				heat_apply(cnt, size);
				multi_me(cnt, size);
				ret_value(cnt, size);
			}
			cnt->y++;
		}
		cnt->x++;
	}
}

void					heat_apply(t_cnt *cnt, t_size *size)
{
	cnt->mx = 0;
	size->coef = 0;
	while (cnt->mx < size->x)
	{
		cnt->my = 0;
		while (cnt->my < size->y)
		{
			if (cnt->x + cnt->mx < size->mapx &&
					cnt->y + cnt->my < size->mapy &&
					size->shape[cnt->mx][cnt->my] == 1 &&
					cnt->heat[cnt->x + cnt->mx][cnt->y + cnt->my] != 1)
				size->coef += cnt->heat[cnt->x + cnt->mx][cnt->y + cnt->my];
			cnt->my++;
		}
		cnt->mx++;
	}
}

void					ret_value(t_cnt *cnt, t_size *size)
{
	if (size->coef < cnt->tmp && size->coef > 0 && cnt->me == 1 && cnt->en == 0)
	{
		if (cnt->x + cnt->mx - 1 < size->mapx &&
				cnt->y + cnt->my - 1 < size->mapy &&
				cnt->me == 1 && cnt->en == 0)
		{
			cnt->tmp = size->coef;
			cnt->retx = cnt->x;
			cnt->rety = cnt->y;
		}
	}
}

int						filler(int fd)
{
	t_size				size;
	t_cnt				cnt;

	cnt_ini(&cnt);
	size_ini(&size);
	player_one(&cnt, fd);
	while (42)
	{
		map_piece_size(&size, &cnt, fd);
		create_heat(&cnt, &size);
		if (!(piece_shape(&size, &cnt, fd)))
			break ;
		is_placeable(&cnt, &size);
		ft_free_shape(&size);
		ft_putnbr(cnt.retx);
		ft_putchar(' ');
		ft_putnbr(cnt.rety);
		ft_putchar('\n');
	}
	ft_free_heat(&cnt, &size);
	ft_free_map(&cnt, &size);
	free(size.shape);
	return (0);
}
