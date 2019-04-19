/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_iso.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/24 15:14:50 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 17:10:52 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_most(t_fdf *f, t_iso *i)
{
	i->nx = 0;
	i->x = i->bx;
	i->y = i->by;
	while (i->nx < (f->size_x - 1))
	{
		i->z0 = (int)round(f->c * (double)(f->map)[i->ny][i->nx]);
		i->z1 = (int)round(f->c * (double)(f->map)[i->ny][i->nx + 1]);
		draw_line(f, setp(i->x, i->y - i->z0),
			setp(i->x + i->delta, i->y + i->delta - i->z1));
		i->z1 = (int)round(f->c * (double)(f->map)[i->ny + 1][i->nx]);
		draw_line(f, setp(i->x, i->y - i->z0),
			setp(i->x - i->delta, i->y + i->delta - i->z1));
		if ((i->nx + 1) == (f->size_x - 1))
		{
			i->z0 = (int)round(f->c * (double)(f->map)[i->ny][i->nx + 1]);
			i->z1 = (int)round(f->c * (double)(f->map)[i->ny + 1][i->nx + 1]);
			draw_line(f, setp(i->x + i->delta, i->y + i->delta - i->z0),
				setp(i->x, i->y + (2 * i->delta) - i->z1));
		}
		i->nx++;
		i->x += i->delta;
		i->y += i->delta;
	}
}

static void	draw_last_line(t_fdf *f, t_iso *i)
{
	i->nx = 0;
	i->x = i->bx - i->delta;
	i->y = i->by + i->delta;
	while (i->nx < (f->size_x - 1))
	{
		i->z0 = (int)round(f->c * (double)(f->map)[i->ny + 1][i->nx]);
		i->z1 = (int)round(f->c * (double)(f->map)[i->ny + 1][i->nx + 1]);
		draw_line(f, setp(i->x, i->y - i->z0),
			setp(i->x + i->delta, i->y + i->delta - i->z1));
		i->nx++;
		i->x += i->delta;
		i->y += i->delta;
	}
}

static int	get_start(t_fdf *f, t_iso i)
{
	if (f->size_x == f->size_y)
		return (SIZE / 2);
	else if (f->size_x > f->size_y)
		return ((SIZE / 2) - ((f->size_x * i.delta) / 4));
	else
		return ((SIZE / 2) + ((f->size_y * i.delta) / 4));
}

void		ft_draw_iso(t_fdf *f)
{
	t_iso	d;

	f->type = 'i';
	if (f->size_x == 1 || f->size_y == 1)
		ft_oneline_iso(f);
	else
	{
		d.delta = ((SIZE / 2) - 50) / ((f->size_x - 1));
		d.ny = 0;
		d.by = (SIZE - ((d.delta * (f->size_y - 1)) +
			(d.delta * (f->size_x - 1)))) / 2;
		d.y = d.by;
		d.bx = get_start(f, d);
		while (d.ny < (f->size_y - 1))
		{
			draw_most(f, &d);
			if ((d.ny + 1) == (f->size_y - 1))
				draw_last_line(f, &d);
			d.ny++;
			d.by += d.delta;
			d.bx -= d.delta;
		}
	}
}
