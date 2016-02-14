/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 02:03:05 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 15:18:15 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

t_int	*int_add(t_int *a, t_int *b)
{
	t_int	*res;

	if (!(res = int_new()))
		return (NULL);
	if (a->inttype == T_INT && b->inttype == T_INT)
	{
		if (!(res->val->intp = malloc(sizeof(long))))
		{
			free(res);
			return (NULL);
		}
		*res->val->intp = *a->val->intp + *b->val->intp;
		res->inttype = T_INT;
	}
	return (res);
}
