/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringparser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 17:54:23 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 18:05:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runtime/parser.h"

void	ft_read_to_queue(char *str, t_o_list **input)
{
	char	*start;

	start = 0;
	while (*str != 0)
	{
		if (*str == '(' || *str == ')' || *str == '*' || *str == '+'
				|| *str == '/' || *str == '%')
		{
			if (start != 0)
				ft_o_list_push_back(ft_strdup_between(start, str), input);
			ft_o_list_push_back(ft_strdup_between(str, str + 1), input);
			start = 0;
		}
		else if (*str == ' ')
		{
			if (start != 0)
				ft_o_list_push_back(ft_strdup_between(start, str), input);
			start = 0;
		}
		else
			start = start == 0 ? str : start;
		str++;
	}
	if (start != 0)
		ft_o_list_push_back(ft_strdup_between(start, str), input);
}
