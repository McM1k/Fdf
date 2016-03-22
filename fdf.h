/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:47:47 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/22 16:59:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	char		*img;
	int			*tab;
}				t_env;

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

int				**reader(int const fd, int **tab);
void			segment(void *mlx, void *win, int xa, int ya, int xb, int yb);

#endif
