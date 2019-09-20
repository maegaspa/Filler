/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:29:00 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 13:43:26 by maegaspa    ###    #+. /#+    ###.fr     */
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
    int                 en;
    int                 tmp;
    int                 me;
	int					**map;
	int					y;
	int					y4;
	int					x;
	int					p;
	int					mx;
	int					my;
	int					m;
	int					starx;
	int					stary;
	int					nb;
	int					player1;
	int					posy;
	int					posx;
	int					**heat;
	int					retx;
	int					rety;
	int					first_heat;
	int					first_map;
	int					first_shape;
}						t_cnt;
typedef struct			s_size
{
	int					coef;
	char				y;
	char				x;
	int					mapy;
	int					mapx;
	int                 mxy;
	int					**shape;
}						t_size;
int						read_map_pieces(char *str);
void					open_map(int fd);
void					cnt_ini(t_cnt *cnt);
void					size_ini (t_size *size);
int						player_one(t_cnt *cnt, int fd);
int						map_parse(t_size *size, t_cnt *cnt, int fd, char *line);
int						ft_atoi_2(char const *str);
int						map_piece_size(t_size *size, t_cnt *cnt, int fd);
int						filler(int fd);
int						cut(char *str);
int						create_heat(t_cnt *cnt, t_size *size);
void					fill_heat(t_size size, t_cnt cnt);
void					place_heat(t_cnt *cnt, t_size *size);
void					cnt_ini2(t_cnt *cnt);
void					place_piece(t_cnt *cnt, t_size *size);
void					aff_map(t_size *size);
void					aff_map2(t_size *size, t_cnt *cnt);
int						piece_shape(t_size *size, t_cnt *cnt, int fd);
void					is_placeable(t_cnt *cnt, t_size *size);
void					heat_apply(t_cnt *cnt, t_size *size);
void					aff_map3(t_size *size, t_cnt *cnt);
void					leftest_star(t_cnt *cnt, t_size *size);
void                    ret_value(t_cnt *cnt, t_size *size);
void                    multi_me(t_cnt *cnt, t_size *size);
void					aff_map3(t_size *size, t_cnt *cnt);
void					aff_map2(t_size *size, t_cnt *cnt);
void					aff_map(t_size *size);
void					ft_free_heat(t_cnt *cnt, t_size *size);
void					ft_free_shape(t_size *size);
void					ft_free_map(t_cnt *cnt, t_size *size);


#endif
