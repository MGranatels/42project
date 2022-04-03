/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:18:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/02/03 16:23:18 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> 

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	diff = (max - min) + 1;
	*range = (int *)malloc(diff * sizeof(int));
	if (range == NULL)
		return (-1);
	while (min < max)
	{
		(**range) = min;
		min ++;
		(*range)++;
	}
	(*range) -= diff - 1;
	return (diff);
}
/*
int main ()
{
	int min = -7;
	int max = -1;
	int *range;
	int len = ft_ultimate_range(&range, min, max);
	//printf("\n");
	for (int i = 0; i < len - 1; i ++)
		printf("%d ", range[i]);
	return (0);
}*/
