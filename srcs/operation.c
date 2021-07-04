/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:03:11 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/05 03:08:15 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(char sign, t_node *stack)
{
	int	tmp;

	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (sign == 'a')
		print("sa");
	else
		print("sb");
}

t_node	*r(char sign, t_stack *info)
{
	t_node	*new;
	t_node	*del;

	new = new_node(info->top->num);
	del = info->top;
	info->top = info->top->next;
	info->top->pre = NULL;
	info->bot->next = new;
	new->pre = info->bot;
	info->bot = new;
	free(del);
	if (sign == 'a')
		print("ra");
	else
		print("rb");
	return (info->top);
}

t_node	*rr(char sign, t_stack *info)
{
	t_node	*new;
	t_node	*del;

	new = new_node(info->bot->num);
	del = info->bot;
	info->bot = info->bot->pre;
	info->bot->next = NULL;
	info->top->pre = new;
	new->next = info->top;
	info->top = new;
	free(del);
	if (sign == 'a')
		print("rra");
	else
		print("rrb");
	return (info->top);
}

void	p(char sign, t_node **push, t_node **pop)
{
	t_node	*new;

	if (!(*pop))
	{
		new = new_node((*push)->num);
		*pop = new;
		*push = (*push)->next;
	}
	else
	{
		new = new_node((*push)->num);
		new->next = *pop;
		(*pop)->pre = new;
		*pop = new;
		if ((*push)->next)
			*push = (*push)->next;
		else
			*push = NULL;
	}
	if (sign == 'a')
		print("pa");
	else
		print("pb");
}
