/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 17:01:37 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 17:02:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

t_llst		*llst_new(void)
{
	t_llst	*res;

	if (!(res = malloc(sizeof(t_llst))))
		return (NULL);
	res->val = NULL;
	res->next = NULL;
	return (res);
}
