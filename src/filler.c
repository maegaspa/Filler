/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:07:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/03 18:25:38 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void		piece_shape(char *line, t_size *size)
{
	int i;

	i = -1;
	if (line[0] == '.' || line[0] == '*')
	{
		while (line[++i])
		{
			if (line[i] == '.')
				size->piece[i] = '.';
			if (line[i] == '*')
				size->piece[i] = '*';
		}
		size->piece[i] = '\0';
		printf("size->piece = %s\n", size->piece);
	}
}

void		filler(int fd)
{
	char	*line;
	t_size	size;
	t_cnt	cnt;

	cnt_ini(&cnt);
	size_ini(&size);
	while (get_next_line(fd, &line) == 1)
	{
		player_one(line, &size, &cnt);
		map_piece_size(&cnt, &size, line);
		map_parse(line, &size, &cnt);
		piece_shape(line, &size);
		create_heat(&cnt, &size);
		//place_piece(&cnt, &size);
		cnt.m++;
	}
	aff_map(&size, &cnt);
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
	printf("enemy = %d\n", size.enemy);
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

//CHOPER UN TRUC POUR LES ETOILES / FORME DE LA PIECE

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
