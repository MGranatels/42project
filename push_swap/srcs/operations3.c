/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:35:01 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/17 13:53:38 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_rrr(t_stk **stack_a, t_stk **stack_b)
{
	ft_rotate2(stack_b);
	ft_rotate2(stack_a);
	printf("rrr\n");
}
