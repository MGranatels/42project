/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:59:45 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/17 17:31:04 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_sorted_list(t_stk *stack)
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



void	check_stack_b(t_stk **stack_b)
{
	if ((*stack_b)->next == NULL)
		return ;
	else if ((*stack_b)->num < (*stack_b)->next->num)
		op_sb(stack_b);
}

void	help_organize(int i, t_stk **stack_a, t_stk **stack_b)
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
		while (i > 0)
		{
			op_ra(stack_a);
			i--;
		}
		op_pb(stack_b, stack_a);
	}
}

void	
	organize_any_element(t_stk **stack_a, t_stk **stack_b, int *arr, int j)
{
	int		i;
	int		x;
	t_stk	*tmp;

	i = 0;
	x = get_size_stack(*stack_a) / 25;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->num <= arr[25 * j])
		{
			help_organize(i, stack_a, stack_b);
			tmp = (*stack_a);
			i = 0;
		}
		i++;
		tmp = tmp->next;
	}
}

void	help_organize2(int i, t_stk **stack_a, t_stk **stack_b)
{
	if (i > (get_size_stack(*stack_b) / 2))
	{
		while (i < get_size_stack(*stack_b))
		{
			op_rrb(stack_b);
			i++;
		}
		op_pa(stack_b, stack_a);
	}
	else
	{
		while (i > 0)
		{
			op_rb(stack_b);
			i--;
		}
		op_pa(stack_b, stack_a);
	}
}

void	organize_any_element2(t_stk **stack_a, t_stk **stack_b, int *arr, int j)
{
	t_stk	*tmp;
	int		i;

	tmp = (*stack_b);
	i = 0;
	while (tmp)
	{
		if (tmp->num == arr[j])
		{
			help_organize2(i, stack_a, stack_b);
			i = 0;
		}
		if ((*stack_b)->next->next == NULL)
		{
			op_pa(stack_b, stack_a);
			op_pa(stack_b, stack_a);
			if ((*stack_a)->num > (*stack_a)->next->num)
				op_sa(stack_a);
			break ;
		}
		i++;
		tmp = tmp->next;
	}	
}

