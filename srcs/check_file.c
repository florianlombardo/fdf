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

#include "../includes/fdf.h"

static void	err_exit(void)
{
	perror("fdf");
	exit(EXIT_FAILURE);
}

static void	check_file(int fd, size_t begin)
{
	size_t	len;
	char	*line;

	while (get_next_line(fd, &line))
	{
		len = ft_strlen_nb(line);
		ft_strdel(&line);
		if (begin != len)
		{
			ft_putendl_fd("Invalid file", 2);
			exit(EXIT_FAILURE);
		}
	}
	if (close(fd) == -1)
		err_exit();
}

void		nofile(char *str)
{
	int		fd;
	char	*line;
	size_t	len;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (get_next_line(fd, &line) == 0)
	{
		ft_putendl_fd("Empty File", 2);
		exit(EXIT_FAILURE);
	}
	else
	{
		len = ft_strlen_nb(line);
		ft_strdel(&line);
		check_file(fd, len);
	}
}
