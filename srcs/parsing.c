/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 17:36:51 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/02 12:55:29 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/parsing.h"

static void	ft_strdel_2d(char ***tab)
{
	int		i;

	i = -1;
	while ((*tab)[i])
		ft_strdel((*tab)[i]);
	free(*tab);
	tab = NULL;
}

char		**parse(char *filename)
{
	int		fd;
	char	**map;

	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		;
	}
	if (close(fd) == -1)
	{
		ft_strdel_2d(&map);
		return (NULL);
	}
	return (map);
}
