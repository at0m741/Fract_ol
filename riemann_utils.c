/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   riemann_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:55:57 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/17 20:52:03 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_dabs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	sign(double n)
{
	if (n < 0)
		return (0);
	return (1);
}

double	approx(double n)
{
	return (n > 0.495 && n < 0.505);
}

double	approx2(double n)
{
	return (n > 0.495 && n < 0.505);
}

unsigned int	get_color_riemann(int i, t_var *f)
{
	unsigned int	color;

	color = 0xFF753BBD;
	color += ((unsigned int)(lissage(i, f)) + sin(2 * 3.14 / i) + 128);
	color += ((unsigned int)lissage(i, f) << 8);
	color += (((unsigned int)lissage(i, f)));
	return (color);
}
