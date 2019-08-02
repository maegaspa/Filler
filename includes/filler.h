/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:29:00 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 16:43:46 by maegaspa    ###    #+. /#+    ###.fr     */
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

typedef struct			s_cnt
{
	int					y;
	int					x;
	int					p;
	int					m;
	int					nb;
	int					player1;
	int					star;
	int					low;
	int					posy;
	int					posx;
	int					**heat;
}						t_cnt;
typedef struct			s_size
{
	char				opponent;
	char				ally;
	char				y;
	char				x;
	int					mapy;
	int					mapx;
	int					enemx;
	int					enemy;
	int					mxy;
}						t_size;
int						read_map_pieces(char *str);
void					open_map(int fd);
void					cnt_ini(t_cnt *cnt);
void					size_ini (t_size *size);
int						player_one(char *line, t_size *size, t_cnt *cnt);
int						map_parse(char *line, t_size *size, t_cnt *cnt);
int						ft_atoi_2(char const *str);
int						map_piece_size(t_cnt *cnt, t_size *size, char *line);
void					filler(int fd);
int						cut(char *str);
void					create_heat(t_cnt *cnt, t_size *size);
void					fill_heat(t_size size, t_cnt cnt);
void					place_heat(t_cnt cnt);
void					cnt_ini2(t_cnt *cnt);
t_cnt					place_piece(t_cnt *cnt, t_size *size, int **heat);
void					aff_map(t_size *size, t_cnt *cnt);

#endif
