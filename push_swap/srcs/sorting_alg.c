/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:59:45 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/11 20:45:32 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


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

void	short_sort(t_stack **stack_a)
{
	t_stack	*tmp;

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
}

void	help_organize(int i, t_stack **stack_a, t_stack **stack_b)
{
	if (i > (get_size_stack(*stack_a) / 2))
	{
		while (i < get_size_stack(*stack_a))
		{
			op_rra(stack_a);
			i++;
		}
		op_pb(stack_b, stack_a);
	}
	else
	{
		while (i != 0)
		{
			op_ra(stack_a);
			i--;
		}
		op_pb(stack_b, stack_a);
	}
}

void	
	organize_any_element(t_stack **stack_a, t_stack **stack_b, int *arr, int j)
{
	int	i;
	t_stack	*tmp;

	tmp = (*stack_a);
	i = 0;
	while(tmp != NULL)
	{
		if (tmp->num == arr[j])
		{
			help_organize(i, stack_a, stack_b);
			i = 0;
		}
		if ((*stack_a)->next->next == NULL)
		{
			op_pb(stack_b, stack_a);
			op_pb(stack_b, stack_a);
			break ;
		}
		i++;
		tmp = tmp->next;
	}
}
