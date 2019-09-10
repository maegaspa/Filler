/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 15:23:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/10 16:18:12 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				map_parse(t_size *size, t_cnt *cnt, int fd, char *line)
{
	cnt->x = 0;
	if (!(cnt->map = malloc(sizeof(int *) * size->mapx)))
		return (0);
	while (cnt->x < size->mapx)
	{
		if (!(get_next_line(fd, &line)))
			return (0);
		cnt->y = 4;
		if (!(cnt->map[cnt->x] = malloc(sizeof(int) * size->mapy)))
			return (0);
		while (cnt->y < size->mapy + 4)
		{
			cnt->map[cnt->x][cnt->y] = 0;
			if ((line[cnt->y] == 'o' || line[cnt->y] == 'O') && cnt->player1)
			{
				cnt->map[cnt->x][cnt->y] = -2;
				cnt->low = 1;
			}
			if ((line[cnt->y] == 'x' || line[cnt->y] == 'X') && (!(cnt->player1)))
			{
				cnt->map[cnt->x][cnt->y] = -2;
				cnt->low = 1;
			}
			if (cnt->player1 && (line[cnt->y] == 'X' || line[cnt->y] == 'x'))
				cnt->map[cnt->x][cnt->y] = 1;
			if ((!(cnt->player1)) && (line[cnt->y] == 'o' || line[cnt->y] == 'O'))
				cnt->map[cnt->x][cnt->y] = 1;
			//dprintf(2, "%d\n", cnt->map[cnt->x][cnt->y]);
			cnt->y++;
		}
		cnt->x++;
		ft_strdel(&line);
	}
	return (1);
}

 
/*int				map_parse(t_size *size, t_cnt *cnt, char *line)
{
	cnt->r = 0;
	if (size->x > size->mapx || size->y > size->mapy)
		return (0);
	cnt->y = 4;
	while (cnt->y++ < size->mapy + 4)
	{
		if ((line[cnt->y] == 'o' || line[cnt->y] == 'O') && cnt->player1)
		{
			cnt->low = 1;
			cnt->posy = cnt->y - 4;
			cnt->posx = ft_atoi(line);
		}
		if (line[cnt->y] == 'x' && (!(cnt->player1)))
		{
			cnt->low = 1;
			cnt->posy = cnt->y - 4;
			cnt->posx = ft_atoi(line);
		}
		if (cnt->player1 && (line[cnt->y] == 'X' || line[cnt->y] == 'x'))
		{
			size->enemy = cnt->y - 4;
			size->enemx = ft_atoi(line);
			if (cnt->r > 0)
				cnt->heat[size->enemx][size->enemy] = 1;
		}
		if ((!(cnt->player1)) && (line[cnt->y] == 'o' || line[cnt->y] == 'O'))
		{
			size->enemy = cnt->y - 4;
			size->enemx = ft_atoi(line);
		}
	}
	cnt->r++;
	return (1);
}*/

int				player_one(t_size *size, t_cnt *cnt, int fd)
{
	char *line;

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
	char *line;
	int i;

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
	/*while (++i < size->mapx + 1)
	{
		if (!(get_next_line(fd, &line)))
			return (0);
		ft_strdel(&line);
	*/
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
