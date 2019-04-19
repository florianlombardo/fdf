/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 17:36:51 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 11:38:41 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t		ft_strlen_nb(char *str)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				ret++;
				while (str[i] >= '0' && str[i] <= '9')
					i++;
			}
			i++;
		}
		return (ret);
	}
	return (0);
}

static void	ft_len(char *str, t_fdf *f)
{
	int		fd;
	char	*tmp;

	f->size_x = 0;
	f->size_y = 0;
	if (!(fd = open(str, O_RDONLY)))
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &tmp))
	{
		if (f->size_y == 0)
			f->size_x = ft_strlen_nb(tmp);
		f->size_y++;
		ft_strdel(&tmp);
	}
	if (close(fd) == -1)
	{
		perror("fdf");
		exit(EXIT_FAILURE);
	}
}

int			*ft_str_to_int(char **str, size_t len, t_fdf *f)
{
	int		*ret;
	size_t	i;

	if (!(ret = malloc(sizeof(int) * len)))
	{
		ft_strdel(str);
		exit(fdferror(f));
	}
	i = 0;
	len = 0;
	while ((*str)[i])
	{
		ret[len] = ft_atoi(&(*str)[i]);
		while ((*str)[i] && (*str)[i] != ' ')
			i++;
		while ((*str)[i] && (*str)[i] == ' ')
			i++;
		len++;
	}
	return (ret);
}

int			ft_parse(t_fdf *f, char *str)
{
	int		fd;
	char	*line;
	size_t	i;

	ft_len(str, f);
	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (1);
	if (!(f->map = malloc(sizeof(int*) * f->size_y)))
		return (1);
	while (get_next_line(fd, &line))
	{
		f->map[i] = ft_str_to_int(&line, f->size_x, f);
		i++;
		ft_strdel(&line);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
