/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   special_cases.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 14:55:31 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 17:10:59 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_line_p(t_fdf *f)
{
	t_para	p;

	p.delta = SIZE / (f->size_x + 2);
	p.nx = 0;
	p.x = (SIZE / 2) - ((p.delta * (f->size_x - 1)) / 2);
	while (p.nx < (f->size_x - 1))
	{
		p.z0 = (int)round(f->c * (double)(f->map)[0][p.nx]);
		p.z1 = (int)round(f->c * (double)(f->map)[0][p.nx + 1]);
		draw_line(f, setp(p.x + p.z0, (SIZE / 2) - (p.z0 / 2)),
			setp(p.x + p.delta + p.z1, (SIZE / 2) - (p.z1 / 2)));
		p.x += p.delta;
		p.nx++;
	}
}

void		ft_oneline_para(t_fdf *f)
{
	t_para p;

	if (f->size_x == 1 && f->size_y > 1)
	{
		p.delta = SIZE / (f->size_y + 2);
		p.ny = 0;
		p.y = (SIZE / 2) - ((p.delta * (f->size_y - 1)) / 2);
		while (p.ny < (f->size_y - 1))
		{
			p.z0 = (int)round(f->c * (double)(f->map)[p.ny][0]);
			p.z1 = (int)round(f->c * (double)(f->map)[p.ny + 1][0]);
			draw_line(f, setp((SIZE / 2) + p.z0, p.y - (p.z0 / 2)),
				setp((SIZE / 2) + p.z1, p.y + p.delta - (p.z1 / 2)));
			p.y += p.delta;
			p.ny++;
		}
	}
	else if (f->size_y == 1 && f->size_x > 1)
		draw_line_p(f);
	else
		mlx_pixel_put(f->pmlx, f->pwin, SIZE / 2, SIZE / 2, 0xffffff);
}

static void	ft_line_i(t_fdf *f)
{
	t_iso	i;

	i.delta = ((SIZE / 2) - 50) / f->size_x;
	i.nx = 0;
	i.x = (SIZE / 2) - ((f->size_x * i.delta) / 3);
	i.y = ((SIZE / 2) - ((i.delta * (f->size_y - 1)) +
		(i.delta * f->size_x))) * 5;
	while (i.nx < (f->size_x - 1))
	{
		i.z0 = (int)round(f->c * (double)(f->map)[0][i.nx]);
		i.z1 = (int)round(f->c * (double)(f->map)[0][i.nx + 1]);
		draw_line(f, setp(i.x, i.y - i.z0),
			setp(i.x + i.delta, i.y - i.z1 + i.delta));
		i.nx++;
		i.y += i.delta;
		i.x += i.delta;
	}
}

void		ft_oneline_iso(t_fdf *f)
{
	t_iso	i;

	if (f->size_x == 1 && f->size_y > 1)
	{
		i.delta = ((SIZE / 2) - 50) / f->size_y;
		i.ny = 0;
		i.x = (SIZE / 2) + ((f->size_y * i.delta) / 3);
		i.y = ((SIZE / 2) - ((i.delta * (f->size_y - 1)) +
			(i.delta * f->size_x))) * 5;
		while (i.ny < (f->size_y - 1))
		{
			i.z0 = (int)round(f->c * (double)(f->map)[i.ny][0]);
			i.z1 = (int)round(f->c * (double)(f->map)[i.ny + 1][0]);
			draw_line(f, setp(i.x, i.y - i.z0),
				setp(i.x - i.delta, i.y - i.z1 + i.delta));
			i.ny++;
			i.y += i.delta;
			i.x -= i.delta;
		}
	}
	else if (f->size_y == 1 && f->size_x > 1)
		ft_line_i(f);
	else
		mlx_pixel_put(f->pmlx, f->pwin, SIZE / 2, SIZE / 2, 0xffffff);
}
