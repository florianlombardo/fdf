/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 12:37:39 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 12:37:40 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	size_y(char *str, int l, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			j++;
			while (str[i] && str[i] != c)
			{
				i++;
				if (l == j)
					k++;
			}
		}
		else
			i++;
	}
	return (k);
}

static int	size_i(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			j++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

static void	fill(char **tab, char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		if (str[i] && str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = 0;
			j++;
		}
		else
			i++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;

	str = (char*)s;
	tab = malloc(sizeof(*tab) * size_i(str, c));
	if (!tab)
		return (0);
	i = 0;
	tab[size_i(str, c) - 1] = 0;
	while (i < size_i(str, c) - 1)
	{
		tab[i] = malloc(sizeof(char) * size_y(str, i + 1, c));
		if (!tab[i])
			return (0);
		i++;
	}
	fill(tab, str, c);
	return (tab);
}
