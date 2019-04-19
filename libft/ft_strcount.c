/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcount.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 12:26:35 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 16:33:12 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strcount(char *str, char c)
{
	size_t			i;
	unsigned int	cmp;

	i = 0;
	cmp = 0;
	while (str[i])
	{
		if (str[i] == c)
			cmp++;
		i++;
	}
	return (cmp);
}
