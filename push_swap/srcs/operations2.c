/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:29:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/30 16:45:10 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void	op_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void	op_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate2(stack_b);
	printf("rr\n");
}

void	op_rra(t_stack **stack_a)
{
	ft_rotate2(stack_a);
	printf("rra\n");
}

void	op_rrb(t_stack **stack_b)
{
	ft_rotate2(stack_b);
	printf("rrb\n");
}
