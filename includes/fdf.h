/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 15:53:15 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 14:58:03 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# define SIZE 1000

typedef struct	s_iso
{
	int			x;
	int			y;
	int			z0;
	int			z1;
	int			delta;
	int			bx;
	int			by;
	size_t		ny;
	size_t		nx;
}				t_iso;

typedef struct	s_para
{
	int			x;
	int			y;
	size_t		nx;
	size_t		ny;
	int			delta;
	int			z0;
	int			z1;
}				t_para;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_fdf
{
	void		*pmlx;
	void		*pwin;
	int			**map;
	size_t		size_x;
	size_t		size_y;
	int			c;
	char		type;
}				t_fdf;

void			nofile(char *str);
int				ft_parse(t_fdf *f, char *str);
void			draw_line(t_fdf *f, t_point a, t_point b);
void			ft_draw_iso(t_fdf *f);
void			ft_oneline_iso(t_fdf *f);
void			ft_draw_para(t_fdf *f);
void			ft_oneline_para(t_fdf *f);
void			free_map(int ***map, size_t size);
int				deal_key(int key, t_fdf *f);
int				fdferror(t_fdf *f);
size_t			ft_strlen_nb(char *str);
t_point			setp(int x, int y);

#endif
