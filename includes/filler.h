/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/27 15:29:00 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/27 18:33:53 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int     read_map_pieces(char *str);
int     main(int ac, char **av);
int     map_parse(char *str);

#endif