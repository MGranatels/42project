/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:20:03 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/19 21:17:30 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sa(t_stk **stack_a)
{
	ft_swap(*stack_a);
	ft_printf("sa\n");
}

void	op_sb(t_stk **stack_b)
{
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void	op_ss(t_stk **stack_a, t_stk **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void	op_pa(t_stk **stack_a, t_stk **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	op_pb(t_stk **stack_b, t_stk **stack_a)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
