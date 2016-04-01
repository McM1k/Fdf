/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 22:17:52 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/01 19:20:55 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void ***tab)
{
	int		i;
	void	**tb;

	i = 0;
	if (*tab)
	{
		tb = *tab;
		while (tb[i])
		{
			ft_memdel(&tb[i]);
			i++;
		}
		ft_memdel(tb);
		*tab = NULL;
		ft_putendl("mdr2");
	}
}
