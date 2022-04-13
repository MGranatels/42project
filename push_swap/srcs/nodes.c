/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:16:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/04/12 09:15:34 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printlist(t_stack *n, char *list)
{
	ft_printf("\n=======%s=======\n", list);
	while (n)
	{
		ft_printf("%d ", n->num);
		n = n->next;
	}
	ft_printf("\n===============\n");
}

t_stack	*create_new_node(int value)
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->num = value;
	s->next = NULL;
	return (s);
}


void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	clean_stack(t_stack	*s)
{
	t_stack *temp;
    if (s) 
	{
        s->next = 0;
        while (s) 
		{
            temp = s->next;
            free(s);
            s = temp;
        }
    }
}

t_stack	*add_elements_to_list2(char **split, t_stack *head, t_stack *stack)
{
	int	j;

	j = 0;
	while (split[j])
	{
		if (is_valid_arg(split[j]))
		{
			stack = create_new_node(ft_atoi(split[j++]));
			stack->next = head;
			head = stack;
		}
		else
		{
			ft_printf("Error\n");
			clean_split(split);
			return (0);
		}
	}
	return (head);
}

t_stack	*add_elements_to_list(int ac, char **av)
{
	t_stack	*stack;
	char	**split;
	t_stack  *head;

	stack = NULL;
	head = NULL;
	while (--ac > 0)
	{
		split = ft_split(av[ac], ' ');
		head = add_elements_to_list2(split, head, stack);
		if (head == NULL)
			return (0);
	}
	clean_split(split);
	if (has_duplicates(head))
	{
		ft_printf("Error\n");
		clean_stack(head);
		return (0);
	}
	return (head);
}
