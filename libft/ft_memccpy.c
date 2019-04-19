/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 12:30:33 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 12:30:34 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	stop;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	stop = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == stop)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
