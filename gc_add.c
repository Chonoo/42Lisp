/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 23:07:57 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/13 23:47:23 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

void	gc_add(t_lvar *var)
{
	gc_lock(pthread_self());
	if (!g_gc_mem.gen1.start)
		g_gc_mem.gen1.start = var;
	else
		g_gc_mem.gen1.end->gc_next = var;
	g_gc_mem.gen1.end = var;
	g_gc_mem.gen1.length += 1;
	gc_unlock(pthread_self());
}
