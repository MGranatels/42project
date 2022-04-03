/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:34:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/31 16:47:22 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_find_prime(int nb)
{
	int	div;

	if (nb < 2)
		return (0);
	div = 2;
	while (nb % div != 0 && div < ((nb / div) + (nb % div)))
		div++;
	if (nb % div == 0 && nb != 2)
		return (0);
	else
		return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_find_prime(nb) && nb < 2147483647)
		nb++;
	return (nb);
}
/*
int main ()
{
	printf("%d\n", ft_find_next_prime(2));
    printf("%d\n", ft_find_next_prime(0));
    printf("%d\n", ft_find_next_prime(1));
    printf("%d\n", ft_find_next_prime(9));
    printf("%d\n", ft_find_next_prime(2147483647));
}
*/
