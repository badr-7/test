/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 08:54:43 by mel-hous          #+#    #+#             */
/*   Updated: 2021/12/02 10:44:34 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	else if (n >= 0 && n <= 9)
	{
		len += ft_putchar (n + '0');
	}
	else if (n < 0)
	{
		len += ft_putchar ('-');
		len += ft_putnbr (n * -1);
	}
	else
	{
		len += ft_putnbr (n / 10);
		len += ft_putnbr (n % 10);
	}
	return (len);
}
