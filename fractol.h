/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:42:07 by ltouzali          #+#    #+#             */
/*   Updated: 2023/12/17 20:52:20 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "mlx/mlx.h"

# define HEIGHT 900
# define WIDTH 900

struct s_frame
{
	void	*img;
	char	*addr;
	int		bit_ppx;
	int		line_size;
	int		endian;
};

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_riemann
{
	double	t1;
	double	t2;
	double	s1;
	double	s2;
	double	h;
	double	w1;
	double	w2;
	double	w3;
	double	w4;
}	t_riemann;

typedef struct s_var
{
	void				*mlx;
	void				*win;
	struct s_frame		*s;
	double				z_r;
	double				z_i;
	double				c_r;
	double				c_i;
	double				a;
	int					max;
	double				x1;
	double				y1;
	struct s_riemann	*r;
	int					onclick;
	int					choose;
	unsigned int		color;
	unsigned int		fade;
	double				ar;
}	t_var;

int				ft_exit(t_var *f);
double			module(double a, double b);
double			mapx(double a, double minb, double maxb);
double			mapy(double a, double minb, double maxb);
int				sign(double n);
double			ft_dabs(double n);
double			approx(double n);
double			approx2(double n);
void			printfractal(t_var *data);
void			ft_putstr(char *c);
void			print_julia(t_var *f);
int				keyhooks(int keycode, t_var *f);
void			draw(t_var *f, int x, int y, unsigned int color);
int				mouse_hook(int button, int x, int y, t_var *f);
unsigned int	mandelbrodt(int x, int y, t_var *f, double zoom);
void			print_mandelbrot(t_var *f);
unsigned int	julia(int x, int y, t_var *f, double zoom);
unsigned int	burningship(int x, int y, t_var *f, double zoom);
void			print_burningship(t_var *f);
void			print_riemann(t_var *f);
void			riemann_setup(t_riemann *r);
void			ft_init_mlx(t_var *new);
unsigned int	riemann(t_var *f, double t, double sigma);
void			zeta(double s_r, double s_i, double *real, double *imag);
void			riemann_choice(t_var *data);
void			julia_choice(t_var *data);
int				loop_hook(t_var *f);

t_var			*ft_init_var(void);
t_riemann		*ft_init_r(double smin, double smax, double tmin, double tmax);

unsigned int	get_color(int i, t_var *f);
unsigned int	get_color_riemann(int i, t_var *f);
double			lissage(int i, t_var *f);

int				ft_strcmp(char *s1, char *s2);
double			ft_atof(const char *nptr);

#endif