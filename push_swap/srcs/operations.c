/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:20:03 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/31 16:40:20 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	printf("sa\n");
}

void	op_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	printf("sb\n");
}

void	op_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	printf("sb\n");
}

void	op_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	printf("pa\n");
}

void	op_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	printf("pb\n");
}
