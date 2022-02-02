/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:16:32 by mel-hous          #+#    #+#             */
/*   Updated: 2021/12/02 10:45:59 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_unsignednb(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
	{
		i += ft_putchar (n + '0');
	}
	else
	{
		i += ft_putnbr (n / 10);
		i += ft_putnbr (n % 10);
	}
	return (i);
}
