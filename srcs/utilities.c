/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 17:38:33 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 12:49:26 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		free_map(int ***map, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

static void	clear_draw(t_fdf *f, int incr, char type)
{
	mlx_clear_window(f->pmlx, f->pwin);
	if (incr == 0)
		f->c = 3;
	else if (incr == 1)
		f->c++;
	else
		f->c--;
	if (type == 'i')
		ft_draw_iso(f);
	else
		ft_draw_para(f);
}

int			deal_key(int key, t_fdf *f)
{
	if (key == 53)
	{
		free_map(&(f->map), f->size_y);
		mlx_destroy_window(f->pmlx, f->pwin);
		exit(EXIT_SUCCESS);
	}
	else if (key == 83)
		clear_draw(f, 0, 'i');
	else if (key == 84)
		clear_draw(f, 0, 'p');
	else if (key == 69)
		clear_draw(f, 1, f->type);
	else if (key == 78)
		clear_draw(f, 2, f->type);
	return (0);
}

int			fdferror(t_fdf *f)
{
	perror("fdf");
	if (f->map)
		free_map(&(f->map), f->size_y);
	mlx_destroy_window(f->pmlx, f->pwin);
	return (EXIT_FAILURE);
}

t_point		setp(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}
