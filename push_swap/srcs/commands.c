/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:03:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/11 20:48:50 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack *node)
{
	int	tmp;

	tmp = node->num;
	node->num = node->next->num;
	node->next->num = tmp;
}

// Rotation makes nb go one node up - First becames the last
void	ft_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	first = *head;
	last = *head;
	while (last->next)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

// Rotation makes nb go one node down - First becames secound last bc first
void	ft_rotate2(t_stack **head)
{
	t_stack	*sec_last;
	t_stack	*last;

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

void	add_front(t_stack **top, t_stack *n)
{
	n->next = (*top);
	n->prev = NULL;
	if (*top != NULL)
		(*top)->prev = n;
	(*top) = n;
}

void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*stack_b == NULL && *stack_a)
	{
		*stack_b = (t_stack *)malloc(sizeof(t_stack));
		(*stack_b)->prev = NULL;
		(*stack_b)->num = (*stack_a)->num;
		(*stack_b)->next = NULL;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	else if (*stack_a)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->num = (*stack_a)->num;
		tmp->next = NULL;
		tmp->prev = NULL;
		add_front(stack_b, tmp);
		*stack_a = (*stack_a)->next;
	}
}
