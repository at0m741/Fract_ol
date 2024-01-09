/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:46:21 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/17 20:48:36 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	riemann_choice(t_var *data)
{
	data->choose = 3;
	data->r = ft_init_r(-14, 8, -16, 16);
	riemann_setup(data->r);
}

void	julia_choice(t_var *data)
{
	data->choose = 1;
	print_julia(data);
}

void	printfractal(t_var *data)
{
	if (data->choose == 0)
		print_mandelbrot(data);
	else if (data->choose == 1)
		julia_choice(data);
	else if (data->choose == 2)
		print_burningship(data);
	else if (data->choose == 3)
		print_riemann(data);
	return ;
}
