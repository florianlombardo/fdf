/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 20:43:30 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 16:33:29 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned int nbr)
{
	int		ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}

char		*ft_uitoa(unsigned int value)
{
	char	*str;
	int		n;
	int		i;

	if (value == 0)
		return (ft_strnew(1));
	i = 1;
	n = ft_count(value);
	str = ft_strnew(n + 1);
	while (value != 0)
	{
		str[n - i] = value % 10;
		value /= 10;
		i++;
	}
	return (str);
}
