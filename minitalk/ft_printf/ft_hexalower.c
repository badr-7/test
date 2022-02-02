/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:21:13 by mel-hous          #+#    #+#             */
/*   Updated: 2021/12/03 18:39:13 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_hexalower(unsigned int nb)
{
	unsigned int	lkharij;
	unsigned int	lbaki;
	int				i;
	int				j;
	char			hexadest[20];

	i = 0;
	lkharij = nb;
	if (lkharij == 0)
		hexadest[i++] = lkharij + 48;
	while (lkharij != 0)
	{
		lbaki = lkharij % 16;
		if (lbaki < 10)
			hexadest[i++] = 48 + lbaki;
		else
			hexadest[i++] = 87 + lbaki;
		lkharij = lkharij / 16;
	}
	j = i;
	hexadest[i--] = '\0';
	while (i >= 0)
		ft_putchar(hexadest[i--]);
	return (j);
}
