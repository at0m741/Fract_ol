/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:14:31 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/26 17:50:05 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	messages(void)
{
	ft_putstr("\033[0;35m  ______              _        _ \033[0m\n");
	ft_putstr("\033[0;35m |  ____|            | |      | |\033[0m\n");
	ft_putstr("\033[0;35m | |__ _ _ __ _  ___ | |_ ___ | |\033[0m\n");
	ft_putstr("\033[0;35m |  __| '_|  _ || __|| __| _ || |\033[0m\n");
	ft_putstr("\033[0;35m | |  | | | (_| ||(_ | | |(_)|| |\033[0m\n");
	ft_putstr("\033[0;35m |_|  |_| |__,_||___|| | |___||_|\033[0m\n");
	ft_putstr("\n\033[0;35m---------fractol choices----------\033[0m\n\n");
	ft_putstr("-mandelbrot\n");
	ft_putstr("-julia \033[0;33m<value 1>\033[0m \033[0;33m<value 2>\033[0m\n");
	ft_putstr("-burningship\n");
	ft_putstr("-Riemann \033[0;33m(mathematical wizarding !)\033[0m\n");
	ft_putstr("\n");
	ft_putstr("\033[0;31mFor informations about Riemann ask ltouzali\033[0m\n");
	exit(EXIT_FAILURE);
}

void	fractal_choice(int ac, char **av, t_var *data)
{
	if (ac == 2 || ac == 4 || ac != 3)
	{
		if (!ft_strcmp(av[1], "julia") && ac == 4)
		{
			if (ac != 4)
				messages();
			data->choose = 1;
			data->c_r = ft_atof(av[2]);
			data->c_i = ft_atof(av[3]);
		}
		else if (!ft_strcmp(av[1], "mandelbrot") && ac == 2)
			data->choose = 0;
		else if (!ft_strcmp("riemann", av[1]) && ac == 2)
			riemann_choice(data);
		else if (!ft_strcmp("burningship", av[1]) && ac == 2)
			data->choose = 2;
		else
		{
			messages();
			exit(EXIT_FAILURE);
		}
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_var			*f_j;

	if (argc > 4 || argc < 2 || argc == 3)
	{
		messages();
		exit(EXIT_FAILURE);
	}
	f_j = ft_init_var();
	fractal_choice(argc, argv, f_j);
	if (f_j->choose == 1 && argc == 3)
		messages();
	ft_init_mlx(f_j);
	if (!f_j->mlx || !f_j->win || !f_j->s->img)
		exit(EXIT_FAILURE);
	printfractal(f_j);
	mlx_hook(f_j->win, 17, 1L << 17, ft_exit, f_j);
	mlx_hook(f_j->win, 33, 1L << 17, ft_exit, f_j);
	mlx_loop_hook(f_j->mlx, loop_hook, f_j);
	mlx_mouse_hook(f_j->win, mouse_hook, f_j);
	mlx_key_hook(f_j->win, keyhooks, f_j);
	mlx_loop(f_j->mlx);
	free(f_j);
	return (0);
}
