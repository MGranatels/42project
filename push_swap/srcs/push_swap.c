/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:22:05 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/19 21:22:25 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

t_stk	*big_stack(t_stk *stk_a, t_stk *stk_b, int size, int *arr)
{
	int	j;

	j = 0;
	while (j < (size / 25))
	{
		organize_any_element(&stk_a, &stk_b, arr, j);
		j++;
	}
	while (stk_a)
	{
		op_pb(&stk_b, &stk_a);
	}	
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

t_stk	*check_sort_algr(int size, t_stk *stk_a, t_stk *stk_b)
{
	int	j;
	int	*arr;

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

int	main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		size;

	if (ac == 1)
		return (0);
	stk_b = NULL;
	stk_a = add_elements_to_list(ac, av);
	size = get_size_stack(stk_a);
	if (size == 2)
	{
		if (stk_a->num > stk_a->next->num)
			op_sa(&stk_a);
		return (0);
	}
	stk_a = check_sort_algr(size, stk_a, stk_b);
	clean_stack(stk_a);
	clean_stack(stk_b);
	system("leaks -- push_swap");
}
