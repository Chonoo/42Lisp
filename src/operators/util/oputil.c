/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oputil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 17:37:43 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 17:37:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_operator(char *str)
{
	char	*operators;

	operators = "+-*/%";
	while (*operators != '\0')
		if (*str == *operators++)
		{
			if (*str != '-')
				return (1);
			else
			{
				if (*(str + 1) != '\0')
					return (0);
				else
					return (1);
			}
		}
	return (0);
}

int		op_prio(char *str)
{
	if (*str == '+' || *str == '-')
		return (1);
	else if (*str == '*' || *str == '/' || *str == '%')
		return (2);
	else
		return (0);
}

int		operator_precedence(char *s1, char *s2)
{
	if (s1 == 0 && s2)
		return (op_prio(s2));
	if (s2 == 0 && s1)
		return (op_prio(s1));
	if (s1 == 0 && s2 == 0)
		return (0);
	return (op_prio(s1) - op_prio(s2));
}
