/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:53:22 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/11 20:45:25 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include "../libft/libft.h"
# include <stdio.h>
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

// typedef struct s_list
// {
// 	int				min;
// 	int				max;
// 	int				size;
// 	struct s_list	*next;
// 	struct s_stack	*end;
// 	t_stack			*(*add)(int ac, char **av, struct s_list list);
// }			t_list;

void	ft_swap(t_stack *node);
void	ft_rotate(t_stack **head);
void	ft_rotate2(t_stack **head);
void	ft_push(t_stack **stack_a, t_stack **stack_b);

void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);
void	op_pb(t_stack **stack_a, t_stack **stack_b);
void	op_pa(t_stack **stack_a, t_stack **stack_b);
void	op_ra(t_stack **stack_a);
void	op_rb(t_stack **stack_b);
void	op_rr(t_stack **stack_a, t_stack **stack_b);
void	op_rra(t_stack **stack_a);
void	op_rrb(t_stack **stack_b);
void	op_rrr(t_stack **stack_a, t_stack **stack_b);
void	add_front(t_stack **top, t_stack *n);

void	printlist(t_stack *n, char *list);
void	short_sort(t_stack **stack_a);
void	insertion_sort(int arr[], int n);

int		*insert_array(t_stack *stack_a, int argms);
int		check_sorted_list(t_stack *stack);
int		count_elements(t_stack **stack);
int		ft_atoi(const char *str);

t_stack	*create_new_node();
t_stack	*add_elements_to_list(int ac, char **av);

#endif