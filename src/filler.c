/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:07:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/03 17:15:04 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int			piece_shape(t_size *size, t_cnt *cnt, int fd)
{
	char	*line;

	cnt->x = 0;
	if (!(size->shape = malloc(sizeof(int *) * size->x)))
		return (0);
	while (cnt->x < size->x)
	{
		get_next_line(fd, &line);
		cnt->y = 0;
		if (!(size->shape[cnt->x] = malloc(sizeof(int) * size->y)))
			return (0);
		while (cnt->y < size->y && (line[0] == '*' || line[0] == '.'))
		{
			if (line[cnt->y] == '*')
				size->shape[cnt->x][cnt->y] = 1;
			if (line[cnt->y] == '.')
				size->shape[cnt->x][cnt->y] = 2;
			cnt->y++;
		}
		cnt->x++;
		ft_strdel(&line);
	}
	return (1);
}

void		is_placeable(t_cnt *cnt, t_size *size)
{
	int coef;
	int x;
	int y;
	int tmp;

	cnt->x = -1;
	tmp = 10000;
	while (++cnt->x < size->mapx)
	{
		cnt->y = -1;
		while (++cnt->y < size->mapy)
		{
			if (cnt->heat[cnt->x][cnt->y] != 1)
			{
				x = -1;
				coef = 0;
				while (++x < size->x)
				{
					y = -1;
					while (++y < size->y)
						if (size->shape[x][y] == 1 && cnt->x + x < size->mapx
							&& cnt->y + y < size->mapy)
							coef += cnt->heat[cnt->x + x][cnt->y + y];
				}
				if (coef < tmp && cnt->heat[cnt->x][cnt->y] == -2)
				{
					tmp = coef;
					cnt->retx = cnt->x;
					cnt->rety = cnt->y;
					y = 0;
					while (size->shape[0][y++] == 2 && size->shape[0][++y] == 1)
						cnt->rety = cnt->y - y;
				}
			}
		}
	}
}

void		filler(int fd)
{
	t_size	size;
	t_cnt	cnt;

	//int fd = open("/Users/maegaspa/Filler/nsm.log", O_RDWR | O_APPEND);
	cnt_ini(&cnt);
	size_ini(&size);
	while (42)
	{
		player_one(&size, &cnt, fd);
		map_piece_size(&size, &cnt, fd);
		create_heat(&cnt, &size);
		piece_shape(&size, &cnt, fd);
		is_placeable(&cnt, &size);
		printf("%d %d\n", cnt.retx, cnt.rety);
		break;
	}
	/*aff_map2(&size, &cnt);
	aff_map(&size);
	printf("-------------\n");
	printf("player = %d\n", cnt.player1);
	printf("ally = %c\n", size.ally);
	printf("opponent = %c\n", size.opponent);
	printf("mapx = %d\n", size.mapx);
	printf("mapy = %d\n", size.mapy);
	printf("piece x = %d\n", size.x);
	printf("piece y = %d\n", size.y);
	printf("low = %d\n", cnt.low);
	printf("posy = %d\n", cnt.posy);
	printf("posx = %d\n", cnt.posx);
	printf("enemx = %d\n", size.enemx);
	printf("enemy = %d\n", size.enemy);*/
}

void		open_map(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		dprintf(2, "%s\n", line);
		ft_strdel(&line);
		i++;
	}
}

/*void		place_piece(t_cnt *cnt, t_size *size)
{
	int		tmp;

	cnt->x = 0;
	while (cnt->x < size->mapx)
	{
		cnt->y = 0;
		while (cnt->y < size->mapy)
		{
			if (heat[cnt->posx][cnt->posy] == heat[cnt->x][cnt->y])
			{
				heat[cnt->x][cnt->y] = heat
			}
			cnt->y++;
		}
		cnt->x++;
	}
}*/
