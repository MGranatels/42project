/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:08:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/03 12:38:29 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ar;
	int	i;

	i = 0;
	if (min >= max)
	{
		ar = NULL;
		return (0);
	}
	ar = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		ar[i] = min;
		i++;
		min++;
	}
	return (ar);
}

/*
int	main(void)
{
	int *test0;
	int i;
	int size;

	size = 9;
	i = 0;
	test0 = ft_range(1, 11);

	for (i = 0; i < size - 1; i++)
	{
		printf("%d - ", test0[i]);
	}
	if (size > 0)
		printf("%d\n", test0[i]);
}*/
