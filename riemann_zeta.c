/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   riemann_zeta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:40:07 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/17 20:52:10 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	zeta(double s_r, double s_i, double *real, double *imag)
{
	int		n;
	double	a;
	double	b;

	n = 1;
	while (n < 700)
	{
		a = cos(s_i * log(n));
		b = sin(s_i * log(n));
		*real += a / ((pow(a, 2) + pow(b, 2)) * pow(n, s_r));
		*imag += -b / ((pow(a, 2) + pow(b, 2)) * pow(n, s_r));
		n++;
	}
}

void	print_riemann(t_var *f)
{
	unsigned int	p;
	double			sigma;
	double			t;
	int				y;
	int				x;

	y = 0;
	while (y < HEIGHT / 2 + 1)
	{
		x = 0;
		t = f->r->t1 + y * (f->r->t2 - f->r->t1) / (HEIGHT);
		while (x < WIDTH)
		{
			sigma = f->r->s1 + x * (f->r->s2 - f->r->s1) / (WIDTH);
			p = riemann(f, t, sigma);
			draw(f, y, x, p);
			draw(f, 900 - y, x, p);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->s->img, 0, 0);
}

void	riemann_setup(t_riemann *r)
{
	r->h = floor(WIDTH * (r->t2 - r->t1) / (r->s2 - r->s1));
	r->w1 = 2.47 / (r->s2 - r->s1);
	r->w2 = (0.47 * r->s1 + 2 * r->s2) / (r->s2 - r->s1);
	r->w3 = 2.24 / (r->t2 - r->t1);
	r->w4 = 1.12 * (r->t2 + r->t1) / (r->t1 - r->t2);
}

unsigned int	riemann(t_var *f, double t, double sigma)
{
	unsigned int	n;
	double			max;
	double			tmp;

	n = 0;
	max = 700;
	zeta(sigma, t, &(f->c_r), &(f->c_i));
	f->c_r = (f->r->w1 * sign(f->c_r) * log(ft_dabs(f->c_r)) + f->r->w2) / 1.4;
	f->c_i = (f->r->w3 * sign(f->c_i) * log(ft_dabs(f->c_i)) + f->r->w4) / 1.4;
	f->z_r = 0;
	f->z_i = 0;
	while (module(f->z_r, f->z_i) <= 12 && n < max)
	{
		tmp = f->z_r;
		f->z_r = (f->z_r * f->z_r) - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * tmp * f->z_i + f->c_i;
		n++;
	}
	if (n == max)
		return (0);
	return (get_color_riemann(n, f));
}
