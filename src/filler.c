/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:07:59 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 13:06:32 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	filler(int fd)
{
	char	*line;
	t_size	size;
	t_cnt	cnt;

	cnt_ini(&cnt);
	size_ini(&size);
	while (get_next_line(fd, &line) == 1)
	{
		player_one(line, &size, &cnt, fd);
		map_piece_size(fd, &cnt, &size, line);
		if (cnt.m > 10)
			map_parse(line, &size, &cnt, fd);
		algo(&cnt, &size, line);
		cnt.m++;
	}
	printf("player = %d\n", cnt.player1);
	printf("ally = %c\n", size.ally);
	printf("opponent = %c\n", size.opponent);
	printf("mapx = %d\n", size.mapx);
	printf("mapy = %d\n", size.mapy);
	printf("piece x = %d\n", size.x);
	printf("piece y = %d\n", size.y);
}

void	open_map(int fd)
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

/*int				read_map_pieces(int fd)
{
	t_cnt cnt;

	cnt.x = -1;
	while (str[++cnt.x])
	{
		get_next_line(0, &str);
		if (cnt.x == 7)
			player_one(str);
		//map_parse(str);
		ft_strdel(&str);
	}
	//place_piece(cnt.x, cnt.y, )
    return (0);
}*/

/*int				place_piece(int xmap, int ymap, int xp, int yp, t_cnt cnt)
{
	char		*piece;


	if (yp > ymap && xp > xmap)
		return (0);
	if (cnt.player1)
		//param de l'algo avec une variable qui prend 'o' ou 'x' selon si P1 ou pas
	//jouer en premier

}*/