/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort_alg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:30:48 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/17 18:29:47 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk	*short_sort_5(t_stk **stack_a, t_stk **stack_b, int *arr)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->num >= arr[3])
		{
			while (i != 0)
			{
				op_ra(stack_a);
				i--;
			}
			op_pb(stack_b, stack_a);
			tmp = (*stack_a);
			if (tmp->num == arr[3] || tmp->num == arr[4])
				op_pb(stack_b, stack_a);
			i = 0;
		}
		i++;
		tmp = tmp->next;
	}
	short_sort_3(stack_a);
	if  ((*stack_b)->num < (*stack_b)->next->num)
		op_sb(stack_b);
	op_pa(stack_b, stack_a);
	op_pa(stack_b, stack_a);
	op_ra(stack_a);
	op_ra(stack_a);
	return ((*stack_a));
}

t_stk	*short_sort_3(t_stk **stack_a)
{
	t_stk	*tmp;

	tmp = (*stack_a)->next;
	if (((*stack_a)->num > tmp->num) && (tmp->num < tmp->next->num)
		&& ((*stack_a)->num < tmp->next->num))
		op_sa(stack_a);
	else if ((*stack_a)->num < tmp->num && tmp->num > tmp->next->num
		&& (*stack_a)->num < tmp->next->num)
	{
		op_sa(stack_a);
		op_ra(stack_a);
	}
	else if ((*stack_a)->num > tmp->num && tmp->num > tmp->next->num
		&& (*stack_a)->num > tmp->next->num)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if ((*stack_a)->num > tmp->num && tmp->num < tmp->next->num
		&& (*stack_a)->num > tmp->next->num)
		op_ra(stack_a);
	else if ((*stack_a)->num < tmp->num && tmp->num > tmp->next->num
		&& (*stack_a)->num > tmp->next->num)
		op_rra(stack_a);
	return(*stack_a);
}