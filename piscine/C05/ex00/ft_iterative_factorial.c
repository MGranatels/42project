/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:53:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/01/31 19:05:29 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	som;

	som = 1;
	if (nb < 0)
		return (0);
	else if (nb <= 1)
		return (1);
	while (nb > 0)
	{
		som *= nb;
		nb--;
	}
	return (som);
}
/*
int main()
{
	printf("%d\n",ft_iterative_factorial(4));
	printf("%d\n",ft_iterative_factorial(0));
	printf("%d\n",ft_iterative_factorial(-1));
}*/
