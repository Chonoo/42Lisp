/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting_yard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 23:36:46 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/20 04:14:46 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double_list.h"

void	ft_read_to_queue(char *str, t_listd **input)
{
	char	*start;

	start = 0;
	while (*str != 0)
	{
		if (*str == '(' || *str == ')' || *str == '*' || *str == '+'
				|| *str == '/' || *str == '%')
		{
			if (start != 0)
				ft_listd_push_back(ft_strdup_between(start, str), input);
			ft_listd_push_back(ft_strdup_between(str, str + 1), input);
			start = 0;
		}
		else if (*str == ' ')
		{
			if (start != 0)
				ft_listd_push_back(ft_strdup_between(start, str), input);
			start = 0;
		}
		else
			start = start == 0 ? str : start;
		str++;
	}
	if (start != 0)
		ft_listd_push_back(ft_strdup_between(start, str), input);
}

void	shunting_yard_simple(t_listd **input, t_listd **output, t_listd **ops)
{
	char *val;

	while (ft_listd_peek(input) != 0)
	{
		val = ft_listd_pop(input);
		if (is_operator(val))
		{
			while (operator_precedence(val, ft_listd_peek(ops)) <= 0)
				ft_listd_push_back(ft_listd_pop(ops), output);
			ft_listd_push_front(val, ops);
		}
		else if (*val == ')')
		{
			while (*(ft_listd_peek(ops)) != '(')
				ft_listd_push_back(ft_listd_pop(ops), output);
			ft_listd_pop(ops);
		}
		else if (*val == '(')
			ft_listd_push_front(val, ops);
		else
			ft_listd_push_back(val, output);
	}
	while (ft_listd_peek(ops))
		ft_listd_push_back(ft_listd_pop(ops), output);
}

t_listd	**shunting_yard(t_listd **input)
{
	t_listd	**output;
	t_listd	**operators;

	output = malloc(sizeof(t_listd*));
	operators = malloc(sizeof(t_listd*));
	output[0] = 0;
	operators[0] = 0;
	shunting_yard_simple(input, output, operators);
	return (output);
}
