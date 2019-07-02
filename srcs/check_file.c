/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 14:00:29 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 13:12:54 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/parsing.h"

static int	check_chars(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
	return (1);
}

static int	check(int fd)
{
	int		len;
	char	*line;
	
	if (!(get_next_line(fd, &line)))
	{
		ft_strdel(&line);
		return (1);
	}
	len = ft_strlen(line);
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		if (len != ft_strlen(line) || !check_chars(line))
		{
			ft_strdel(&line);
			return (1);
		}
		ft_strdel(&line);
	}
	return (0);
}

int			check_file(char *filename)
{
	int		fd;
	int		ret;
	
	ret = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (1);
	if (!check(fd))
		ret = 1;
	if (close(fd) == -1)
		return (1);
	return (ret);
}
