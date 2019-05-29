/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uhtoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 15:05:26 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/25 16:30:09 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len(long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_uhtoa(long long n)
{
	int		i;
	char	*str;

	if (n < 0)
		n = 65536 - n;
	i = len(n);
	if (!(str = malloc((sizeof(char) * i))))
		return (0);
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

/*static int		len(short n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int		one(short n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_uhtoa(short n)
{
	int		i;
	int		tmp2;
	char	*str;

	if (n < 0)
	{
		str = ft_memalloc(7);
		str = ft_strcpy(str, "-65535");
		return (str);
	}
	tmp2 = one(n);
	i = len(n);
	if (!(str = ft_memalloc(i + tmp2)))
		return (0);
	while (i--)
	{
		str[i + tmp2] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

static int		len(long long n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_uhtoa(short n)
{
	int		i;
	char	*str;

	if (n < 0)
		n = 65536 - n;
	if (n > 65535)
		n = 65536 + n;
	i = len(n);
	if (!(str = malloc((sizeof(char) * i))))
		return (0);
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}*/