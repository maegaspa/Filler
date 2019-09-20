/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/13 15:42:35 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 16:59:12 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void			cnt_ini(t_cnt *cnt)
{
	cnt->starx = 0;
	cnt->stary = 0;
	cnt->y = 0;
	cnt->x = 0;
	cnt->mx = 0;
	cnt->my = 0;
	cnt->nb = 0;
	cnt->player1 = 0;
	cnt->posy = 0;
	cnt->posx = 0;
	cnt->retx = 0;
	cnt->rety = 0;
	cnt->first_heat = 0;
	cnt->first_map = 0;
	cnt->first_shape = 0;
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
}

int				ft_atoi_2(char const *str)
{
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || ft_isalpha(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	//dprintf(2, "*[%s]*\n", str);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		//dprintf(2, "[%d]-[%c]\n", nbr, str[i]);
		i++;
	}
	return (nbr);
}

int				cut(char *str)
{
	int			i;
	int			j;
	int			nbr;
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
	nbr = ft_atoi_2(dest);
	ft_strdel(&dest);
	return (nbr);
}

void		ft_free_heat(t_cnt *cnt, t_size *size)
{
	int i;

	if (cnt->heat)
	{
		i = -1;
    	while (++i < size->mapy - 1)
    		free(cnt->heat[i]);
    	free(cnt->heat);
    	cnt->heat = NULL;
	}
}

void		ft_free_shape(t_size *size)
{
	int i;

   	if (size->shape)
	{
		i = -1;
		while (++i < size->x)
            free(size->shape[i]);
        free(size->shape);
        size->shape = NULL;
	}
}

void	ft_free_map(t_cnt *cnt, t_size *size)
{
	int i;

	if (cnt->map)
    {
    	i = -1;
        while (++i < size->mapy - 1)
			free(cnt->map[i]);
		free(cnt->map);
		cnt->map = NULL;
	}
}
