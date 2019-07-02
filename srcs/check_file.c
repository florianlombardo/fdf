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

static int	count_chars(char *str)
{
	int		i;
	int		cmp;

	i = -1;
	cmp = 0;
	while (str[++i])
	{
		while (str[i] != ' ')
			i++;
		if (str[i] && ft_isdigit(str[i]))
			cmp++;
	}
	return (cmp);
}

static int	check(int fd)
{
	int		len;
	int		nblines;
	char	*line;
	
	if (!(get_next_line(fd, &line)))
	{
		ft_strdel(&line);
		return (-1);
	}
	len = count_chars(&line);
	ft_strdel(&line);
	nblines = 1;
	while (get_next_line(fd, &line))
	{
		if (!check_chars(line) || (count_chars(line) != len))
		{
			ft_strdel(&line);
			return (-1);
		}
		nblines++;
		ft_strdel(&line);
	}
	return (nblines);
}

int			check_file(char *filename)
{
	int		fd;
	int		ret;
	
	ret = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	ret = check(fd);
	if (close(fd) == -1)
		return (-1);
	return (ret);
}
