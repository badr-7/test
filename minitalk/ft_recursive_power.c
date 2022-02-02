/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:10:11 by mel-hous          #+#    #+#             */
/*   Updated: 2021/10/10 08:44:02 by mel-hous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if ((nb == 0 && power == 0) || power < 1)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
/*int main()
{
    printf("%d",ft_recursive_power(2, 4));
    return 0;
}*/
