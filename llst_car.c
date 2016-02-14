/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_car.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:55:19 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 17:03:22 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

inline t_lvar	*llst_car(t_llst *lst, int *errn)
{
	if (!lst)
	{
		error_raise(errn, ERR_IS_NULL);
		return (NULL);
	}
	return (lst->val);
}
