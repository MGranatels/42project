/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:20:06 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/04/30 17:00:30 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*big_stack(t_stk *stk_a, t_stk *stk_b, int size, int *arr)
{
	int	j;
	int	brk;

	j = 1;
	if (size == 500)
		brk = 45;
	else if (size == 100)
		brk = 20;
	else
		brk = 30;
	while (j < (size / brk))
	{
		organize_any_element(&stk_a, &stk_b, arr, j);
		j++;
	}
	while (stk_a)
		op_pb(&stk_b, &stk_a);
	size = size - 1;
	while (stk_b)
	{
		organize_any_element2(&stk_a, &stk_b, arr, size);
		size--;
	}
	return (stk_a);
}

t_stk	*short_stack(t_stk *stk_a, t_stk *stk_b, int size, int *arr)
{
	if (size == 3)
		stk_a = short_sort_3(&stk_a);
	else if (size == 5)
		stk_a = short_sort_5(&stk_a, &stk_b, arr);
	else
	{
		while (stk_a)
			op_pb(&stk_b, &stk_a);
		size = size - 1;
		while (stk_b)
		{
			organize_any_element2(&stk_a, &stk_b, arr, size);
			size--;
		}
	}
	return (stk_a);
}

int	check_sorted_list(t_stk **stack)
{
	t_stk	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stk	*check_sort_algr(int size, t_stk *stk_a, t_stk *stk_b)
{
	int	j;
	int	*arr;

	if (check_sorted_list(&stk_a))
		return (stk_a);
	arr = insert_array(stk_a, size);
	j = 0;
	if (size >= 25)
		stk_a = big_stack(stk_a, stk_b, size, arr);
	else
		stk_a = short_stack(stk_a, stk_b, size, arr);
	if (arr)
		free(arr);
	return (stk_a);
}
