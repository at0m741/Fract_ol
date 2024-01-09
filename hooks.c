/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:42:22 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/17 20:57:11 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_fractal(t_var *f)
{
	if (f->choose == 0)
		print_mandelbrot(f);
	else if (f->choose == 1)
		print_julia(f);
	else if (f->choose == 2)
		print_burningship(f);
}

int	loop_hook(t_var *f)
{
	int	x;
	int	y;

	if (f->onclick == 1)
	{
		mlx_mouse_get_pos(f->mlx, f->win, &x, &y);
		f->c_r = mapx((double) x / f->a + f->x1, -2, 2);
		f->c_i = mapy((double) y / f->a + f->y1, -2, 2);
		print_fractal(f);
	}
	return (1);
}

int	mouse_hook(int button, int x, int y, t_var *f)
{
	if (button == 4)
	{
		f->x1 = (double)(x / f->a + f->x1) - (x / (f->a * 1.2));
		f->y1 = (double)(y / f->a + f->y1) - (y / (f->a * 1.2));
		f->a *= 1.2;
	}
	if (button == 5)
	{
		f->x1 = (double)(x / f->a + f->x1) - (x / (f->a / 1.2));
		f->y1 = (double)(y / f->a + f->y1) - (y / (f->a / 1.2));
		f->a /= 1.2;
	}
	if (button == 1)
		f->onclick = !f->onclick;
	print_fractal(f);
	return (0);
}

int	keyhooks(int keycode, t_var *f)
{
	if (keycode == 65307)
		ft_exit(f);
	if (keycode == 65363)
		f->x1 += 10 * f->a;
	if (keycode == 65361)
		f->x1 -= 10 * f->a;
	if (keycode == 65362)
		f->y1 += 10 * f->a;
	if (keycode == 65364)
		f->y1 -= 10 * f->a;
	if (keycode == 65436)
		f->max /= 1.1;
	if (keycode == 65451)
		f->max += 20;
	if (keycode == 65453)
		f->max -= 20;
	if (keycode == 65433)
		f->max = 600;
	if (keycode == 114)
		f->fade += 0x00210150;
	print_fractal(f);
	return (1);
}
