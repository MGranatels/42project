/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:34:19 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/04/26 09:33:48 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	insertion_sort(int arr[], int n)
{
	int	i;
	int	key;
	int	j;

	i = 0;
	while (++i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int	*insert_array(t_stk *stk_a, int argms)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * argms + 1);
	i = 0;
	while (stk_a)
	{
		arr[i++] = stk_a->num;
		stk_a = stk_a->next;
	}
	insertion_sort(arr, i);
	return (arr);
}
