/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:20:03 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/12 11:40:41 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	ft_printf("sa\n");
}

void	op_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void	op_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void	op_pa(t_stack **stack_a, t_stack **stack_b){
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	op_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
