/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:34:19 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/04/11 20:44:28 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(int arr[], int n)
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

int	*insert_array(t_stack *stack_a, int argms)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * argms + 1);
	i = 0;
	while (stack_a)
	{
		arr[i++] = stack_a->num;
		stack_a = stack_a->next;
	}
	insertion_sort(arr, i);
	return (arr);
}