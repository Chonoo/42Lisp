/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 13:24:17 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 16:22:51 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_O_LIST_H
# define FT_O_LIST_H
# include <stdlib.h>
# include "../../strings/util/ft_strutil.h"

typedef struct		s_o_list
{
	struct s_o_list	*next;
	struct s_o_list	*last;
	char			*value;
}					t_o_list;

t_o_list			*ft_o_list_create_elem(char *str);

void				ft_o_list_push_front(char *str, t_o_list **head);

void				ft_o_list_push_back(char *str, t_o_list **head);

char				*ft_o_list_pop(t_o_list **head);

char				*ft_o_list_peek(t_o_list **head);

t_o_list			*ft_o_list_find(char *value);

char				*ft_o_list_delink(t_o_list *item);

char				*ft_o_list_fdel(char *value);

#endif
