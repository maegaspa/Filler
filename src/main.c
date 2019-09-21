/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:08:06 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/21 18:37:47 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int			main(void)
{
	int		fd;

	fd = 0;
	filler(fd);
	return (0);
}

void		ft_free_heat(t_cnt *cnt, t_size *size)
{
	int		i;

	if (cnt->heat)
	{
		i = -1;
		while (++i < size->mapx)
			free(cnt->heat[i]);
		free(cnt->heat);
		cnt->heat = NULL;
	}
}

void		ft_free_shape(t_size *size)
{
	int		i;

	if (size->shape)
	{
		i = -1;
		while (++i < size->x)
			free(size->shape[i]);
		free(size->shape);
		size->shape = NULL;
	}
}

void		ft_free_map(t_cnt *cnt, t_size *size)
{
	int		i;

	if (cnt->map)
	{
		i = -1;
		while (++i < size->mapx)
			free(cnt->map[i]);
		free(cnt->map);
		cnt->map = NULL;
	}
}

void		piece_size(char *line, char **split, t_size *size)
{
	if (line[0] == 'P' && line[1] == 'i')
	{
		split = ft_strsplit(line, ' ');
		size->x = ft_atoi(split[1]);
		size->y = ft_atoi(split[2]);
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
	}
}
