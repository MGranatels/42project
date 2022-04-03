/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:59:45 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/31 18:05:33 by mgranate         ###   ########.fr       */
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

int	count_elements(t_stack **stack)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = (*stack);
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	check_sorted_list(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			i = 0;
		stack = stack->next;
	}
	return (i);
}
