/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 23:10:00 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 16:24:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_o_list.h"

t_o_list	*ft_o_list_create_elem(char *str)
{
	t_o_list	*list;

	list = malloc(sizeof(t_o_list));
	if (list)
	{
		list->next = 0;
		list->last = 0;
		list->value = str;
	}
	return (list);
}

void		ft_o_list_push_front(char *str, t_o_list **head)
{
	t_o_list	*tmp;
	t_o_list	*list;

	if (head == 0)
		return ;
	list = head[0];
	if (list == 0)
	{
		head[0] = ft_o_list_create_elem(0);
		ft_o_list_push_front(str, head);
		return ;
	}
	tmp = ft_o_list_create_elem(str);
	if (list->next != 0)
	{
		tmp->next = list->next;
		tmp->next->last = tmp;
	}
	else
	{
		tmp->next = list;
		list->last = tmp;
	}
	list->next = tmp;
	tmp->last = list;
}

void		ft_o_list_push_back(char *str, t_o_list **head)
{
	t_o_list	*tmp;
	t_o_list	*list;

	if (head == 0)
		return ;
	list = head[0];
	if (list == 0)
	{
		head[0] = ft_o_list_create_elem(0);
		ft_o_list_push_back(str, head);
		return ;
	}
	tmp = ft_o_list_create_elem(str);
	if (list->last != 0)
	{
		tmp->last = list->last;
		tmp->last->next = tmp;
	}
	else
	{
		tmp->last = list;
		list->next = tmp;
	}
	list->last = tmp;
	tmp->next = list;
}

char		*ft_o_list_pop(t_o_list **head)
{
	t_o_list	*list;
	t_o_list	*tmp;
	char		*str;

	if (head == 0 || head[0] == 0)
		return (0);
	list = head[0];
	tmp = list->next;
	if (tmp == 0)
		return (0);
	if (tmp->next == list)
		list->next = 0;
	else
		list->next = tmp->next;
	if (list->last == tmp)
		list->last = 0;
	str = tmp->value;
	free(tmp);
	return (str);
}

char		*ft_o_list_peek(t_o_list **head)
{
	t_o_list	*list;

	if (head == 0 || head[0] == 0)
		return (0);
	list = *head;
	if (list->next != 0)
		return (list->next->value);
	else
		return (0);
}
