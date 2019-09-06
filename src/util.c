/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 15:42:35 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/06 18:18:32 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void			cnt_ini(t_cnt *cnt)
{
	cnt->y = 0;
	cnt->x = 0;
	cnt->mx = 0;
	cnt->my = 0;
	cnt->nb = 0;
	cnt->player1 = 0;
	cnt->low = 0;
	cnt->posy = 0;
	cnt->posx = 0;
	cnt->retx = 0;
	cnt->rety = 0;
}

void			cnt_ini2(t_cnt *cnt)
{
	cnt->p = 2;
	cnt->y = 0;
	cnt->x = 0;
}

void			size_ini(t_size *size)
{
	size->y = 0;
	size->x = 0;
	size->mapy = 0;
	size->mapx = 0;
	size->enemx = 0;
	size->enemy = 0;
}

int				ft_atoi_2(char const *str)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || ft_isalpha(str[i])
			|| str[i] == '%' || str[i] == '0' || str[i] == '+' || str[i] == '-'
			|| str[i] == '#' || str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	return (nbr);
}

int				cut(char *str)
{
	int			i;
	int			j;
	char		*dest;

	i = -1;
	j = 0;
	if (!(dest = malloc(sizeof(char) * j + 1)))
		return (0);
	while (str[++i])
	{
		if (ft_isdigit(str[i - 2]) && str[i - 1] == ' ' && ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				dest[j++] = str[i++];
		}
	}
	free(dest);
	return (ft_atoi_2(dest));
}
