/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 23:47:07 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/20 01:09:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strutil.h"

int		ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(char *str)
{
	int		length;
	char	*res;
	int		i;

	length = ft_strlen(str);
	res = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i <= length)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	*ft_strdup_between(char *start, char *end)
{
	char	*tmp;
	int		ctr;

	tmp = malloc(sizeof(char) * (int)(end - start + 1));
	ctr = 0;
	while (ctr < (int)(end - start))
	{
		tmp[ctr] = start[ctr];
		ctr++;
	}
	tmp[ctr] = '\0';
	return (tmp);
}

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '\0' || *s1 != *s2)
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}
