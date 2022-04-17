/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:22:05 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/17 18:56:46 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*big_stack(t_stk *stack_a, t_stk *stack_b, int size, int *arr)
{
	int j;

	j = 0;
	while (j < (size / 25))
	{
		organize_any_element(&stack_a, &stack_b, arr, j);
		j++;
	}
	while (stack_a)
	{
		op_pb(&stack_b, &stack_a);
	}	
	size = size - 1;
	while (stack_b)
	{
		organize_any_element2(&stack_a, &stack_b, arr, size);
		size--;
	}
	return (stack_a);
}

t_stk	*short_stack(t_stk *stack_a, t_stk *stack_b, int size, int *arr)
{
	if (size == 3)
		stack_a = short_sort_3(&stack_a);
	else if (size == 5)
		stack_a = short_sort_5(&stack_a, &stack_b, arr);
	else 
	{
		while (stack_a)
			op_pb(&stack_b, &stack_a);
		size = size - 1;
		while (stack_b)
		{
			organize_any_element2(&stack_a, &stack_b, arr, size);
			size--;
		}
	}
	return (stack_a);
}

t_stk	*check_sort_algr(int size, t_stk *stack_a, t_stk *stack_b)
{
	int j;
	int *arr;
	
	arr = insert_array(stack_a, size);
	j = 0;
	if (size >= 25)
		stack_a = big_stack(stack_a, stack_b, size, arr);
	else
		stack_a = short_stack(stack_a, stack_b, size, arr);
	return (stack_a);
}


int main (int ac, char **av)
{
	t_stk	*stack_a;
	t_stk	*stack_b;
	int		size;

	stack_b = NULL;
	stack_a = add_elements_to_list(ac, av);
	size = get_size_stack(stack_a);
	stack_a = check_sort_algr(size ,stack_a, stack_b);
}