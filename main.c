/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:08:06 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 17:16:47 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/filler.h"

int         main()//int ac, char **av)
{
	int		fd;
/*
    if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		filler(fd);
		//printf("%d %d\n", cnt.retx, cnt.rety);
		//printf("%d %d\n", cnt->retx, cnt->rety);
		//create_heat(cnt, size);
		close(fd);
	}*/
	fd = 0;
	filler(fd);
    return (0);
}
