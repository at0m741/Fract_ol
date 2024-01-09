/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_inits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:01:01 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/26 16:37:12 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_riemann	*ft_init_r(double s1, double s2, double t1, double t2)
{
	t_riemann	*new;

	new = malloc(sizeof(t_riemann));
	new->s1 = s1;
	new->s2 = s2;
	new->t1 = t1;
	new->t2 = t2;
	return (new);
}

void	draw(t_var *f, int x, int y, unsigned int color)
{
	char	*addr;

	addr = f->s->addr + (y * f->s->line_size + x * (f->s->bit_ppx / 8));
	*(unsigned int *)addr = color;
}

void	ft_init_mlx(t_var *new)
{
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WIDTH, HEIGHT, "fract-ol");
	new->s = malloc(sizeof(struct s_frame));
	new->s->img = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	new->s->addr = mlx_get_data_addr(new->s->img, &(new->s->bit_ppx), \
	&(new->s->line_size), &(new->s->endian));
}

t_var	*ft_init_var(void)
{
	t_var	*new;

	new = malloc(sizeof(t_var));
	if (new == NULL)
		return (NULL);
	new->z_r = 0;
	new->z_i = 0;
	new->c_r = 0;
	new->c_i = 0;
	new->a = 1;
	new->color = 0xFF753BBD;
	new->fade = 0x00000000;
	new->max = 50;
	new->x1 = 0;
	new->y1 = 0;
	new->onclick = 0;
	new->choose = -1;
	new->ar = (double) WIDTH / (double) HEIGHT;
	return (new);
}
