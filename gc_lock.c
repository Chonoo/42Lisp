/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 22:51:39 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/13 23:49:32 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

t_gc_mem	g_gc_mem = { 0 };

/*
** unlock_gc returns -1 in case of error (illegal access).
** Valid usage of this feature is during thread exit. During such exits
** (that can be sudden) checking the return value is not necessary. Any
** thread lock gets released and g_gc_mem is freed for usage by other threads.
*/

int			gc_unlock(pthread_t thread)
{
	if (pthread_equal(g_gc_mem.thread, thread))
	{
		g_gc_mem.lock = 0;
		return (1);
	}
	else
		return (-1);
}

/*
** Always use lock_gc before accessing g_gc_mem
** This way you are guaranteed that g_gc_mem is available
** and will not be changed under your feet
*/

int			gc_lock(pthread_t thread)
{
	lock:
	while (g_gc_mem.lock && !pthread_equal(g_gc_mem.thread, thread))
		usleep(100);
	g_gc_mem.thread = thread;
	g_gc_mem.lock = 1;
	if (!pthread_equal(g_gc_mem.thread, thread))
		goto lock;
	return (1);
}
