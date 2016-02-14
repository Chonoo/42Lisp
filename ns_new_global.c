/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_new_global.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 15:51:04 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 16:28:52 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lisp.h"

/*
** Hashes have to be printable
*/

int		ns_global_hash(char *str)
{
	int		res;

	res = *str - ' ';
	if (*(str + 1))
		res += *(str + 1) - ' ';
	return (res);
}

t_lvar	*ns_global_get(t_nshash *glob, char *str, int *errn)
{
	int		hres;
	t_nshi	*bucket;

	hres = ns_global_hash(str);
	bucket = glob->buckets[hres];
	while (bucket && ft_strcmp(bucket->name, str))
		bucket = bucket->next;
	if (!bucket)
	{
		error_raise(errn, ERR_NOT_DEFINED);
		return (NULL);
	}
	else
		return (bucket->value);
}

void	ns_global_add(t_nshash *glob, char *str, t_lvar *var, int *errn)
{
	int		hres;
	t_nshi	*bucket;

	hres = ns_global_hash(str);
	bucket = glob->buckets[hres];
	if (!bucket)
	{
		if (!(glob->buckets[hres] = nshash_new_bucket(str, var)))
			error_raise(errn, ERR_NO_MEM);
		return ;
	}
	while (bucket && bucket->next)
		bucket = bucket->next;
	if (!(bucket->next = nshash_new_bucket(str, var)))
		error_raise(errn, ERR_NO_MEM);
}

t_nshash	*ns_global_new(int *errn)
{
	t_nshash	*res;

	if (!(res = malloc(sizeof(t_nshash))))
	{
		error_raise(errn, ERR_NO_MEM);
		return (NULL);
	}
	if (!(res->buckets = malloc(sizeof(t_nshi *) * 188)))
	{
		free(res);
		error_raise(errn, ERR_NO_MEM);
		return (NULL);
	}
	res->hash = &ns_global_hash;
	res->get = &ns_global_get;
	res->add = &ns_global_add;
	res->parent = NULL;
	return (res);
}
