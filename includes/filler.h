/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:29:00 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 13:06:19 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <stdio.h>

int							read_map_pieces(char *str);
int							main(int ac, char **av);
//int						place_piece(int xmap, int ymap, int xp, int yp, t_cnt cnt);
void						open_map(int fd);
typedef struct				s_cnt
{
	int						y;
	int						x;
	int						k;
	int						m;
	int						nb;
	int						player1;
	int						star;
	int						low;
	int						pos;
}							t_cnt;
typedef struct				s_size
{
	char					opponent;
	char					ally;
	char					y;
	char					x;
	int						mapy;
	int						mapx;
}							t_size;
void            			cnt_ini(t_cnt *cnt);
void            			size_ini (t_size *size);
int							player_one(char *line, t_size *size, t_cnt *cnt, int fd);
int							map_parse(char *line, t_size *size, t_cnt *cnt, int fd);
int							ft_atoi_2(char const *str);
int							map_piece_size(int fd, t_cnt *cnt, t_size *size, char *line);
void						filler(int fd);
int							cut(char *str);
int             			algo(t_cnt *cnt, t_size *size, char *line);

#endif