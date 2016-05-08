/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:47:47 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/08 18:35:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# define SIZE_X 2400
# define SIZE_Y 1300

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*ig;
	char		*img;
	int			**tab;
	double		**mat;
	int			siz;
	int			bit;
	int			end;
	int			x_decal;
	int			y_decal;
	double		zoom;
	int			x_rot;
	int			y_rot;
	int			z_rot;
}				t_env;

typedef struct	s_dot
{
	int			x;
	int			y;
	int			color;
}				t_dot;

int				**reader(int const fd, int **tab);
void			segment(t_env env, t_dot a, t_dot b);
void			drawer(t_env env);
t_dot			convert(int x, int y, int z, t_env env);
void			img_addr(t_env env, int x, int y, int color);
void			ft_quit();

#endif
