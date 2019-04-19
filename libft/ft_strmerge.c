/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmerge.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 11:35:31 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 11:38:04 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmerge(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (str);
}
