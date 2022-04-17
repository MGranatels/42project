/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:29:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/17 13:53:29 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_ra(t_stk **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	op_rb(t_stk **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	op_rr(t_stk **stack_a, t_stk **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate2(stack_b);
	ft_printf("rr\n");
}

void	op_rra(t_stk **stack_a)
{
	ft_rotate2(stack_a);
	ft_printf("rra\n");
}

void	op_rrb(t_stk **stack_b)
{
	ft_rotate2(stack_b);
	ft_printf("rrb\n");
}
