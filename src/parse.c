/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 15:23:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 18:35:42 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				map_parse(char *line, t_size *size, t_cnt *cnt, int fd)
{
	cnt->y = 4;
	if (size->x > size->mapx || size->y > size->mapy)
		return (0);
	while (cnt->y < size->mapy + 4)
	{
		if (line[cnt->y] != '.' && line[cnt->y] != 'X' && line[cnt->y] != 'O'
			&& line[cnt->y] != 'x' && line[cnt->y] != 'o')
			return (0);
		printf("line[cnt->y] = %c", line[cnt->y]);
		if (line[cnt->y] == 'o' || line[cnt->y] == 'x')
		{
			cnt->low = 1;
			cnt->pos = cnt->y;
		}
		printf("cnt->y = %d\n", cnt->y);
		cnt->y++;
	}
	return (1);
}

int			player_one(char *line, t_size *size, t_cnt *cnt, int fd)
{
	if (cnt->m == 5 && line[17] == 'm' && line[18] == 'a')
	{
		cnt->player1 = 1;
		size->ally = 'O';
		size->opponent = 'X';
		return (0);
	}
	if (cnt->m == 5 && line[17] != 'm' && line[18] != 'a')
	{
		size->ally = 'X';
		size->opponent = 'O';
	}
	return (0);
}

int			map_piece_size(int fd, t_cnt *cnt, t_size *size, char *line)
{
	if (cnt->m == 9)
	{
		size->mapx = ft_atoi_2(line);
		size->mapy = cut(line);
	}
	if (cnt->m == (11 + size->mapx))
	{
		size->x = ft_atoi_2(line);
		size->y = cut(line);
	}
	return (1);
}
