/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 20:16:10 by sujeon            #+#    #+#             */
/*   Updated: 2021/07/06 03:23:38 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *info, t_node *stack_a)
{
	if (info->size <= 5)
		sort_under_5(info, stack_a);
	else
		sort_over_5(info, stack_a);
}
