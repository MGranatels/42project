/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:59:45 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/15 20:10:04 by mgranate         ###   ########.fr       */
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

// void	help_organize2(int i, t_stack **stack_a, t_stack **stack_b)
// {
// 	if (i > (get_size_stack(*stack_a) / 2))
// 	{
// 		while (i < get_size_stack(*stack_a))
// 		{
// 			op_rra(stack_a);
// 			i++;
// 		}
// 		op_pb(stack_b, stack_a);
// 	}
// 	else
// 	{
// 		while (i != 0)
// 		{
// 			op_ra(stack_a);
// 			i--;
// 		}
// 		op_pb(stack_b, stack_a);
// 	}
// }

void	check_stack_b(t_stack **stack_b)
{
	if ((*stack_b)->next == NULL)
		return ;
	else if ((*stack_b)->num < (*stack_b)->next->num)
		op_sb(stack_b);
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
	int		i;
	int		k;
	int		x;
	t_stack	*tmp;

	i = 0;
	k = j + 1;
	x = get_size_stack(*stack_a) / 20;
	tmp = (*stack_a);
	while (get_size_stack(*stack_b) <= 20 * k)
	{
		if (tmp->num >= arr[0] && tmp->num <= arr[20 * k])
		{
			help_organize(i, stack_a, stack_b);
			tmp = (*stack_a);
			i = 0;
		}
		i++;
		tmp = tmp->next;
	}
}

void	help_organize2(int i, t_stack **stack_a, t_stack **stack_b)
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

void	organize_any_element2(t_stack **stack_a, t_stack **stack_b, int *arr, int j)
{
	t_stack	*tmp;
	int		i;

	tmp = (*stack_b);
	i = 0;
	while (tmp != NULL)
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
			break ;
		}
		i++;
		tmp = tmp->next;
	}	
}
