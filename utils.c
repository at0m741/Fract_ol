/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:20:26 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/26 17:41:47 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

double	ft_atof(const char *nptr)
{
	double	res;
	double	frac;
	int		i;

	res = 0.0;
	frac = 1.0;
	i = 0;
	if (nptr[i] == '-' )
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = res * 10.0 + (nptr[i++] - '0');
	if (nptr[i] == '.')
	{
		i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			frac *= 0.1;
			res = res * 10.0 + (nptr[i++] - '0') * frac;
		}
	}
	if (nptr[0] == '-')
		return (res * -1);
	return (res);
}

void	ft_putchar(char str)
{
	write(1, &str, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_exit(t_var *f)
{
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_image(f->mlx, f->s->img);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	free(f->s);
	if (f->choose == 3)
		free(f->r);
	free(f);
	exit(0);
}
