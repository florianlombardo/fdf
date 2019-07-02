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

#include "../includes/parsing.h"

int		main(int ac, char **av)
{
	char	**map;
	int		nblines;

	if (ac == 2)
	{
		if ((nblines = check_file(argv[1])) == -1)
			return (EXIT_FAILURE);
		if (!(map = parse(argv[1], nblines)))
			return (EXIT_FAILURE);
	}
	else
	{
		ft_putendl_fd("Usage : ./fdf <filename>", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
