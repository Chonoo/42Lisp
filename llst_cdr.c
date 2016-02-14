/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_cdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:56:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 17:04:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

inline t_llst	*llst_cdr(t_llst *lst, int *errn)
{
	if (!lst)
	{
		error_raise(errn, ERR_IS_NULL);
		return (NULL);
	}
	return (lst->next);
}
