/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 20:43:30 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 16:32:59 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nbr, int base)
{
	int		ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	tab[17];
	int		n;
	int		i;

	if (value == 0)
		return (ft_strnew(1));
	i = 1;
	ft_strcpy(tab, "0123456789abcdef");
	n = ft_count(value, base);
	str = ft_strnew(n + 1 + (value < 0 ? 1 : 0));
	while (value != 0)
	{
		str[n - i] = tab[value % base];
		value /= base;
		i++;
	}
	return (str);
}
