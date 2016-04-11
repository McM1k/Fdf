/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:47:47 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/11 19:30:09 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# define SIZE_X 2550
# define SIZE_Y 1400

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*ig;
	char		*img;
	int			**tab;
	int			bit;
	int			siz;
	int			end;
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
t_dot			convert(int x, int y, int z, t_dot dot);
void			img_addr(t_env env, int x, int y, int color);

#endif
