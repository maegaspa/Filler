/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 15:23:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 16:59:09 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				map_parse(t_size *size, t_cnt *cnt, int fd, char *li)
{
	cnt->x = -1;
	if (!(cnt->map = malloc(sizeof(int *) * size->mapx)))
		return (0);
	while (++cnt->x < size->mapx)
	{
		if (!(get_next_line(fd, &li)))
			return (0);
		cnt->y = 3;
		if (!(cnt->map[cnt->x] = malloc(sizeof(int) * size->mapy)))
			return (0);
		while (++cnt->y < size->mapy + 4)
		{
			cnt->map[cnt->x][cnt->y] = 0;
			if ((li[cnt->y] == 'o' || li[cnt->y] == 'O') && cnt->player1 == 1)
				cnt->map[cnt->x][cnt->y] = -2;
			if ((li[cnt->y] == 'x' || li[cnt->y] == 'X') && cnt->player1 == 2)
				cnt->map[cnt->x][cnt->y] = -2;
			if (cnt->player1 == 1 && (li[cnt->y] == 'X' || li[cnt->y] == 'x'))
				cnt->map[cnt->x][cnt->y] = 1;
			if (cnt->player1 == 2 && (li[cnt->y] == 'o' || li[cnt->y] == 'O'))
				cnt->map[cnt->x][cnt->y] = 1;
		}
		ft_strdel(&li);
	}
	return (1);
}

int				player_one(t_size *size, t_cnt *cnt, int fd)
{
	char		*line;

	if (!(get_next_line(fd, &line)))
		return (0);
	if (line[10] == '1')
	{
		cnt->player1 = 1;
		size->ally = 'O';
		size->opponent = 'X';
		return (0);
	}
	if (line[10] == '2')
	{
		cnt->player1 = 2;
		size->ally = 'X';
		size->opponent = 'O';
	}
	ft_strdel(&line);
	return (1);
}

int				map_piece_size(t_size *size, t_cnt *cnt, int fd)
{
	char		*line;
	int			i;

	i = -1;
	if (!(get_next_line(fd, &line)))
		return (0);
	if (line[0] == 'P' && line[1] == 'l')
	{
		size->mapx = ft_atoi_2(line);
		size->mapy = cut(line);
	}
	ft_strdel(&line);
	get_next_line(fd, &line);
	ft_strdel(&line);
	map_parse(size, cnt, fd, line);
	if (!(get_next_line(fd, &line)))
		return (0);
	if (line[0] == 'P' && line[1] == 'i')
	{
		size->x = ft_atoi_2(line);
		size->y = cut(line);
	}
	ft_strdel(&line);
	return (1);
}

int				piece_shape(t_size *size, t_cnt *cnt, int fd)
{
	char		*line;

	cnt->x = 0;
	if (!(size->shape = malloc(sizeof(int *) * size->x)))
		return (0);
	while (cnt->x < size->x)
	{
		if (!(get_next_line(fd, &line)))
			return (0);
		cnt->y = 0;
		if (!(size->shape[cnt->x] = malloc(sizeof(int) * size->y)))
			return (0);
		while (line && cnt->y < size->y)
		{
			if (line[cnt->y] == '*')
				size->shape[cnt->x][cnt->y] = 1;
			if (line[cnt->y] == '.')
				size->shape[cnt->x][cnt->y] = 2;
			cnt->y++;
		}
		cnt->x++;
	}
	ft_strdel(&line);
	return (1);
}
