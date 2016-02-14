/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvar_new_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 13:44:49 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 15:12:24 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

static inline t_int	*lvar_new_int_aslong(char *str, int *errn)
{
	char	*endp;
	long	v;
	t_int	*tmp;

	endp = 0;
	v = ft_strtol(str, &endp, 10);
	if (!(*endp))
	{
		if (!(tmp = int_new()))
		{
			error_raise(errn, ERR_NO_MEM);
			return (NULL);
		}
		if (!(tmp->val->intp = malloc(sizeof(long))))
		{
			free(tmp);
			error_raise(errn, ERR_NO_MEM);
			return (NULL);
		}
		*tmp->val->intp = v;
		tmp->inttype = T_INT;
		return (tmp);
	}
	return (NULL);
}

t_lvar		*lvar_new_int(char *str, int *errn)
{
	t_lvar	*res;

	if (!(res = lvar_new()))
		return (NULL);
	if (!(res->val->intp = lvar_new_int_aslong(str, errn)))
	{
		if (*errn)
		{
			error_print_stack("New Int (system function)");
			free(res);
			return (NULL);
		}
		else
		{
			error_raise(errn, ERR_UNIMPLEMENTED);
			return (NULL); // TODO: Fix more cases
		}
	}
	else
	{
		res->type = T_INTP;
		return (res);
	}
	return (NULL);
}
