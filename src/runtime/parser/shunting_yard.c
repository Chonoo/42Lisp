/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting_yard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 23:36:46 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 18:09:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runtime/parser.h"

void		shunting_yard_simple(t_o_list **input,
		t_o_list **output, t_o_list **ops)
{
	char		*val;

	while (ft_o_list_peek(input) != 0)
	{
		val = ft_o_list_pop(input);
		if (is_operator(val))
		{
			while (operator_precedence(val, ft_o_list_peek(ops)) <= 0)
				ft_o_list_push_back(ft_o_list_pop(ops), output);
			ft_o_list_push_front(val, ops);
		}
		else if (*val == ')')
		{
			while (*(ft_o_list_peek(ops)) != '(')
				ft_o_list_push_back(ft_o_list_pop(ops), output);
			ft_o_list_pop(ops);
		}
		else if (*val == '(')
			ft_o_list_push_front(val, ops);
		else
			ft_o_list_push_back(val, output);
	}
	while (ft_o_list_peek(ops))
		ft_o_list_push_back(ft_o_list_pop(ops), output);
}

t_o_list	**shunting_yard(t_o_list **input)
{
	t_o_list	**output;
	t_o_list	**operators;

	output = malloc(sizeof(t_o_list*));
	operators = malloc(sizeof(t_o_list*));
	output[0] = 0;
	operators[0] = 0;
	shunting_yard_simple(input, output, operators);
	return (output);
}
