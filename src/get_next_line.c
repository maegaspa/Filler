/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 17:54:02 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/02 17:52:40 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int				ft_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((int)s[i] == c)
			return (i);
		i++;
	}
	if ((int)s[i] == c)
		return (i);
	return (-1);
}

static int		cut_line(char **line, char *tab[10240], int fd, int x)
{
	char	*tmp;

	tmp = NULL;
	if (x == -1)
		x = ft_strlen(tab[fd]);
	if (!(*line = ft_strsub(tab[fd], 0, x)))
		return (-1);
	tmp = tab[fd];
	if (!(tab[fd] = ft_strsub(tab[fd], x + 1, ft_strlen(tab[fd]) - x)))
		return (-1);
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*tab[10240];
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	int				x;

	x = 0;
	tmp = NULL;
	if (fd < 0 || fd >= 10240 || !line ||
			BUFF_SIZE < 1 || read(fd, buffer, 0) < 0 ||
			(!tab[fd] && !(tab[fd] = ft_strnew(0))))
		return (-1);
	while ((ft_index(tab[fd], '\n') == -1)
			&& (x = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[x] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin(tab[fd], buffer);
		free(tmp);
	}
	if (x <= 0 && !ft_strlen(tab[fd]))
	{
		ft_strdel(&tab[fd]);
		return (0);
	}
	return (cut_line(line, tab, fd, ft_index(tab[fd], '\n')));
}
