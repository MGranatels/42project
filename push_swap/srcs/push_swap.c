/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:22:05 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/21 15:07:51 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	first_look(t_stk **stk, int *arr, int j)
{
	int	i;
	t_stk	*tmp;

	tmp = *stk;
	i = 0;
	while (tmp)
	{
		if (tmp->num <= arr[25 * j])
			break ;
		i ++;
		tmp = tmp->next;
	}
	return (i);
}	

int	last_look(t_stk **stk, int size, int *arr, int j)
{
	int	i;
	int c;
	int total;
	t_stk *tmp;
	
	tmp = *stk;
	c = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->num <= arr[25 * j])
			c = i;
		i++;
		tmp = tmp->next;
	}
	total = size - c;
	return (total);
}	

void	help_organize_test(int c, int c1, t_stk **stack_a, t_stk **stack_b)
{
	if (c < c1)
	{
		while (c > 0)
		{
			op_rra(stack_a);
			c--;
		}
		op_pb(stack_b, stack_a);
	}
	else
	{
		while (c1 > 0)
		{
			op_ra(stack_a);
			c1--;
		}
		op_pb(stack_b, stack_a);
	}
}
void	
	organize_any_element_test(t_stk **stk_a, t_stk **stk_b, int *arr, int j, int size)
{
	int		i;
	t_stk	*tmp;
	int c;
	int c1;

	i = 0;
	tmp = (*stk_a);
	while (tmp)
	{
		if (tmp->num <= arr[25 * j])
		{
			c = last_look(stk_a, size, arr, j);
			c1 = first_look(stk_a, arr, j);
			help_organize_test(c, c1, stk_a, stk_b);
			tmp = (*stk_a);
			i = 0;
		}
		i++;
		tmp = tmp->next;
	}
}

t_stk	*big_stack(t_stk *stk_a, t_stk *stk_b, int size, int *arr)
{
	int	j;

	j = 1;
	while (j < (size / 25))
	{
		organize_any_element_test(&stk_a, &stk_b, arr, j, size);
		j++;
	}
	// while (j < (size / 25))
	// {
	// 	organize_any_element(&stk_a, &stk_b, arr, j);
	// 	j++;
	// }
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
		clean_stack(&stk_a);
		clean_stack(&stk_b);
		return (0); 	
	}
	stk_a = check_sort_algr(size, stk_a, stk_b);
	clean_stack(&stk_a);
	clean_stack(&stk_b);
	system("leaks -- push_swap");
}
