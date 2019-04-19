/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:06:45 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 16:17:08 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_gnl2(char *full, unsigned int *i, char **line)
{
	unsigned int	start;

	start = *i;
	while (full[*i] != '\n' && full[*i] != '\0')
		(*i)++;
	*line = ft_strnew(*i - start + 1);
	*line = ft_strncpy(*line, &full[start], *i - start);
	if (full[*i] != '\0')
		(*i)++;
}

int		get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	int					ret;
	static char			*full;
	static unsigned int	i;

	if (fd == -1)
		return (-1);
	ft_bzero(buff, BUFF_SIZE);
	if (full == NULL)
		full = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		full = ft_strjoin_free(full, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	if (full[i] != '\0')
	{
		ft_gnl2(full, &i, line);
		return (1);
	}
	return (0);
}
