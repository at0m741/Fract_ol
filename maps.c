/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:39 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/13 18:11:25 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	module(double a, double b)
{
	return ((a * a) + (b * b));
}

double	mapx(double a, double minb, double maxb)
{
	return (a * ((maxb - minb) / WIDTH) + minb);
}

double	mapy(double a, double minb, double maxb)
{
	return (a * ((maxb - minb) / HEIGHT) + minb);
}
