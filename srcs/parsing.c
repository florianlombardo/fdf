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

char	**parse(char *filename)
{
	int		fd;
	char	**ret;

	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	if (!(map = malloc()))
	{
		;
	}
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
