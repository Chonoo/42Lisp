/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_str_is_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 21:14:41 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/17 21:16:52 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

int		parser_str_is_int(char *str)
{
		while (*str)
			if (ft_isdigit(*str))
				str++;
		if (*str)
			return (0);
		else
			return (1);
}
