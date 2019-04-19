/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stradd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 12:29:34 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 12:32:33 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *str, char c)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(str);
	ret = ft_strnew(len + 2);
	ft_strcpy(ret, str);
	ret[len] = c;
	ft_strdel(&str);
	return (ret);
}
