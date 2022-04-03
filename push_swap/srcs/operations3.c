/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:35:01 by mgranate          #+#    #+#             */
/*   Updated: 2022/03/30 16:45:13 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate2(stack_b);
	ft_rotate2(stack_a);
	printf("rrr\n");
}
