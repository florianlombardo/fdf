/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <flombard@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/23 16:08:46 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/23 12:55:29 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_fdf	f;

	if (ac == 2)
	{
		nofile(av[1]);
		if (ft_parse(&f, av[1]))
			return (fdferror(&f));
		f.pmlx = mlx_init();
		f.pwin = mlx_new_window(f.pmlx, SIZE, SIZE, "fdf");
		f.c = 3;
		ft_draw_iso(&f);
		mlx_key_hook(f.pwin, deal_key, &f);
		mlx_loop(f.pmlx);
	}
	else
	{
		ft_putendl_fd("Usage : ./fdf <filename>", 2);
		return (EXIT_FAILURE);
	}
	mlx_destroy_window(f.pmlx, f.pwin);
	free_map(&(f.map), f.size_y);
	return (EXIT_SUCCESS);
}
