/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:08:06 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 18:35:44 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/filler.h"
#include <stdio.h>

int         main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		//filler(fd);
		open_map(fd);
		close(fd);
	}
    return (0);
}