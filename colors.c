/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:31:59 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/17 20:52:04 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	lissage(int i, t_var *f)
{
	return (i - log((log(f->z_r * f->z_r + f->z_i * f->z_i)) / log(2)));
}

unsigned int	get_color(int i, t_var *f)
{
	f->color = 0xFF753BBD;
	f->color += ((unsigned int)(lissage(i, f)) << 16);
	f->color += ((unsigned int)(lissage(i, f)) << 8);
	f->color += ((unsigned int)(lissage(i, f)));
	return (f->color);
}
