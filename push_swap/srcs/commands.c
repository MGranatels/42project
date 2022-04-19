/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:03:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/19 21:22:16 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stk *node)
{
	int	tmp;

	tmp = node->num;
	node->num = node->next->num;
	node->next->num = tmp;
}

// Rotation makes nb go one node up - First becames the last
void	ft_rotate(t_stk **head)
{
	t_stk	*first;
	t_stk	*last;

	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

// Rotation makes nb go one node down - First becames secound last bc first
void	ft_rotate2(t_stk **head)
{
	t_stk	*sec_last;
	t_stk	*last;

	sec_last = NULL;
	last = *head;
	while (last->next)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	add_front(t_stk **top, t_stk *n)
{
	n->next = (*top);
	n->prev = NULL;
	if (*top != NULL)
		(*top)->prev = n;
	(*top) = n;
}

void	ft_push(t_stk **stack_a, t_stk **stack_b)
{
	t_stk	*tmp;

	tmp = NULL;
	if (stack_a && *stack_a)
	{
		if (stack_b && !*stack_b)
		{
			*stack_b = *stack_a;
			*stack_a = (*stack_a)->next;
			(*stack_b)->next = NULL;
		}
		else
		{
			tmp = *stack_b;
			*stack_b = *stack_a;
			*stack_a = (*stack_a)->next;
			(*stack_b)->next = tmp;
		}
	}
}
