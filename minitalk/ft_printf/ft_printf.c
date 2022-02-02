/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:33:46 by mel-hous          #+#    #+#             */
/*   Updated: 2021/12/03 18:44:39 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

static int	ft_if(const char first, va_list p)
{
	int	len;

	len = 0;
	if (first == 'c')
		len += ft_putchar(va_arg(p, int));
	if (first == 's')
		len += ft_putstr(va_arg(p, char *));
	if (first == 'd' || first == 'i')
		len += ft_putnbr(va_arg(p, int));
	if (first == 'u')
		len += ft_unsignednb(va_arg(p, unsigned int));
	if (first == '%')
		len += ft_putchar('%');
	if (first == 'X')
		len += ft_hexaupper(va_arg(p, unsigned int));
	if (first == 'x')
		len += ft_hexalower(va_arg(p, unsigned int));
	if (first == 'p')
		len += ft_p(va_arg(p, unsigned long int));
	return (len);
}

int	ft_printf(const char *first, ...)
{
	int		i;
	int		len;
	va_list	p;

	va_start(p, first);
	len = 0;
	i = 0;
	if (first == NULL)
		return (0);
	while (first[i] != '\0')
	{
		if (first[i] == '%')
		{
			i++;
			len += ft_if(first[i], p);
			i++;
		}
		if (first[i] == '%')
			continue ;
		if (first[i] == '\0')
			break ;
		len += ft_putchar(first[i++]);
	}
	va_end(p);
	return (len);
}
