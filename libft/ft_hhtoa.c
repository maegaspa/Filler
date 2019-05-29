/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hhtoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/15 15:05:52 by maegaspa     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/24 15:46:09 by maegaspa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		len(char n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

static int		one(char n)
{
	if (n < 0)
		return (1);
	return (0);
}

char			*ft_hhtoa(char n)
{
	int		i;
	int		tmp2;
	char	*str;

	if (n == -128)
	{
		str = ft_memalloc(5);
		str = ft_strcpy(str, "-128");
		return (str);
	}
	tmp2 = one(n);
	if (n < 0)
		n = -n;
	i = len(n);
	if (!(str = ft_memalloc(i + tmp2)))
		return (0);
	tmp2 == 1 ? str[0] = '-' : 0;
	while (i--)
	{
		str[i + tmp2] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}