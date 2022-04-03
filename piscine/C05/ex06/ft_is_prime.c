/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:34:35 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/01 16:52:26 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_prime(int nb)
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

int main()
{
	printf("%d", ft_is_prime(2147483647));
}
