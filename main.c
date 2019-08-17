/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:08:06 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 18:30:45 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/filler.h"

/*int         main(void)
{
	char *str;
	
	printf("NTM\n");
	while (get_next_line(0, &str) > 0)
	{
		//filler(fd);
		printf("%s\n", str);
		free(str);
	}
    return (0);
}*/

int         main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		return (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		filler(fd);
		//printf("%d %d\n", cnt->retx, cnt->rety);
		//create_heat(cnt, size);
		close(fd);
	}
    return (0);
}