/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:02:21 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/15 20:16:43 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_burningship(t_var *f)
{
	unsigned int	p;
	double			zoom;
	int				y;
	int				x;

	zoom = 1 / f->a;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			p = burningship(x, y, f, zoom);
			draw(f, x, y, p);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->s->img, 0, 0);
}

unsigned int	burningship(int x, int y, t_var *f, double zoom)
{
	double			tmp;
	int				i;

	i = 0;
	f->c_r = mapx((double) x * zoom + f->x1, -2, 2);
	f->c_i = mapy((double) y * zoom + f->y1, -2, 2);
	f->z_r = 0;
	f->z_i = 0;
	while (module(f->z_r, f->z_i) < 12 && i < (int)f->max)
	{
		tmp = f->z_r;
		f->z_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
		f->z_i = 2 * fabs(tmp * f->z_i) + f->c_i;
		i++;
	}
	if (i == (int)f->max)
		return (0);
	return ((get_color(i, f) + f->fade) % 0x00FFFFFF);
}
