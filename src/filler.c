/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:07:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/29 05:27:20 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void		filler(int fd)
{
	char	*line;
	int		**heat;
	t_size	size;
	t_cnt	cnt;

	cnt_ini(&cnt);
	size_ini(&size);
	while (get_next_line(fd, &line) == 1)
	{
		player_one(line, &size, &cnt);
		map_piece_size(&cnt, &size, line);
		if (cnt.m > 10)
		{
			if (map_parse(line, &size, &cnt))
			{
				heat = create_heat(&cnt, &size);
				place_piece(&cnt, &size, heat);
			}
		}
		cnt.m++;
	}
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
}

void		open_map(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		dprintf(fd, "%3d : %s\n", i, line);
		ft_strdel(&line);
		i++;
	}
}

int				place_piece(t_cnt *cnt, t_size *size, int **heat)
{
	int		rightheat;
	int		retx;
	int		rety;

	rightheat = 0;

	if (heat[cnt->x][cnt->y] == rightheat)
	{	
		retx = cnt->x;
		rety = cnt->y;
	}
	return(cnt)
}