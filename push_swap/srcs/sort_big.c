/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anne-sophie <anne-sophie@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:21:34 by anne-sophie       #+#    #+#             */
/*   Updated: 2022/04/26 09:28:17 by anne-sophie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	first_look(t_stk **stk, int *arr, int j, int brk)
{
	int	i;
	t_stk	*tmp;

	tmp = *stk;
	i = 0;
	while (tmp)
	{
		if (tmp->num <= arr[brk * j])
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}	

int	last_look(t_stk **stk, int size, int *arr, int j, int brk)
{
	int	i;
	int c;
	t_stk *tmp;
	
	tmp = *stk;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->num <= arr[brk * j])
			c = i;
		i++;
		tmp = tmp->next;
	}
	c = size - c;
	return (c);
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
	organize_any_element(t_stk **stk_a, t_stk **stk_b, int *arr, int j, int size)
{
	int		brk;
	t_stk	*tmp;
	int 	c;
	int 	c1;
	
	if (size == 500)
		brk = 45;
	else if (size == 100)
		brk = 20;
	else
		brk = 30;
	tmp = (*stk_a);
	while (tmp)
	{
		if (tmp->num <= arr[brk * j])
		{
			c = last_look(stk_a, size, arr, j, brk);
			c1 = first_look(stk_a, arr, j, brk);
			help_organize_test(c, c1, stk_a, stk_b);
			tmp = (*stk_a);
		}
		tmp = tmp->next;
	}
}
