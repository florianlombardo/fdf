/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 12:28:53 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 12:28:54 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_count(int n, int *w)
{
	int		l;

	l = 0;
	*w = 1;
	if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 0)
	{
		if (n >= 10)
			*w *= 10;
		l++;
		n /= 10;
	}
	return (l);
}

static char	*ft_mini(void)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (0);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static char	*ft_fill(int n, char *str, int len, int wei)
{
	int		i;

	i = 0;
	len = ft_count(n, &wei);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i++;
	}
	while (wei > 0)
	{
		str[i] = (n / wei) + '0';
		n = n % wei;
		wei /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_zero(void)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		wei;
	char	*str;

	str = NULL;
	wei = 0;
	len = 0;
	if (n == -2147483648)
		str = ft_mini();
	else if (n == 0 || n == -0)
		str = ft_zero();
	else
		str = ft_fill(n, str, len, wei);
	return (str);
}
