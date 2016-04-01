/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 22:17:52 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/01 22:34:15 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void ***tab)
{
	int		i;
	void	**tb;

	i = 0;
	if (tab)
	{
		tb = *tab;
		while (tb[i])
		{
			if (tb[i])//WHY
				ft_memdel(&tb[i]);
			i++;
		}
		if (tb)
			ft_memdel(tb);
		*tab = NULL;
	}
}
