/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_para.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/18 13:29:44 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 17:38:10 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_line(t_fdf *f, t_point a, t_point b)
{
	t_line	l;

	l.dx = (int)fabs((double)(b.x - a.x));
	l.dy = (int)fabs((double)(b.y - a.y));
	l.sx = (a.x < b.x) ? 1 : -1;
	l.sy = (a.y < b.y) ? 1 : -1;
	l.err = ((l.dx > l.dy) ? l.dx : -l.dy) / 2;
	while (1)
	{
		mlx_pixel_put(f->pmlx, f->pwin, a.x, a.y, 0xffffff);
		if (a.x == b.x && a.y == b.y)
			break ;
		l.err2 = l.err;
		if (l.err2 > -l.dx)
		{
			l.err -= l.dy;
			a.x += l.sx;
		}
		if (l.err2 < l.dy)
		{
			l.err += l.dx;
			a.y += l.sy;
		}
	}
}

static void	draw_most(t_fdf *f, t_para *p)
{
	p->nx = 0;
	p->x = (SIZE / 2) - ((p->delta * (f->size_x - 1)) / 2);
	while (p->nx < (f->size_x - 1))
	{
		p->z0 = (int)round(f->c * (double)(f->map)[p->ny][p->nx]);
		p->z1 = (int)round(f->c * (double)(f->map)[p->ny][p->nx + 1]);
		draw_line(f, setp(p->x + p->z0, p->y - (p->z0 / 2)),
			setp(p->x + p->delta + p->z1, p->y - (p->z1 / 2)));
		p->z1 = (int)round(f->c * (double)(f->map)[p->ny + 1][p->nx]);
		draw_line(f, setp(p->x + p->z0, p->y - (p->z0 / 2)),
			setp(p->x + p->z1, p->y + p->delta - (p->z1 / 2)));
		if ((p->nx + 1) == (f->size_x - 1))
		{
			p->z0 = (int)round(f->c * (double)(f->map)[p->ny][p->nx + 1]);
			p->z1 = (int)round(f->c * (double)(f->map)[p->ny + 1][p->nx + 1]);
			draw_line(f, setp(p->x + p->delta + p->z0, p->y - (p->z0 / 2)),
				setp(p->x + p->delta + p->z1, p->y + p->delta - (p->z1 / 2)));
		}
		p->nx++;
		p->x += p->delta;
	}
}

static void	draw_last_line(t_fdf *f, t_para *p)
{
	p->nx = 0;
	p->x = (SIZE / 2) - ((p->delta * (f->size_x - 1)) / 2);
	while (p->nx < (f->size_x - 1))
	{
		p->z0 = (int)round(f->c * (double)(f->map)[p->ny + 1][p->nx]);
		p->z1 = (int)round(f->c * (double)(f->map)[p->ny + 1][p->nx + 1]);
		draw_line(f, setp(p->x + p->z0, p->y + p->delta - (p->z0 / 2)),
			setp(p->x + p->delta + p->z1, p->y + p->delta - (p->z1 / 2)));
		p->nx++;
		p->x += p->delta;
	}
}

void		ft_draw_para(t_fdf *f)
{
	t_para	p;

	f->type = 'p';
	if (f->size_x == 1 || f->size_y == 1)
		ft_oneline_para(f);
	else
	{
		p.delta = (int)fmin((double)(SIZE / (f->size_x + 2)),
			(double)(SIZE / (f->size_y + 2)));
		p.ny = 0;
		p.y = (SIZE / 2) - ((p.delta * (f->size_y - 1)) / 2);
		while (p.ny < (f->size_y - 1))
		{
			draw_most(f, &p);
			if ((p.ny + 1) == (f->size_y - 1))
				draw_last_line(f, &p);
			p.ny++;
			p.y += p.delta;
		}
	}
}
