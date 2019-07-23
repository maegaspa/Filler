/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 15:58:47 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/22 13:50:01 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int             algo(t_cnt *cnt, t_size *size, char *line)
{
	int	**heat;

	if (!(tab = malloc(sizeof(int *) * size->mapx)))
		return (0);
	while (cnt->x < size->mapx)
	{
		if(!(tab[x] = malloc(sizeof(int **) * size->mapy)))
			return (0);
		cnt.y = 0;
		while (cnt->y < size->mapy)
		{
			cnt->y++;
		}
		cnt->x++;
	}
}