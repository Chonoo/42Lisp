/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 23:12:52 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/20 02:02:44 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLE_LIST_H
# define FT_DOUBLE_LIST_H
# include <stdlib.h>
# include "operator_util.h"
# include "ft_strutil.h"

typedef struct		s_listd
{
	struct s_listd	*next;
	struct s_listd	*last;
	char			*value;
}					t_listd;

t_listd				*ft_listd_create_elem(char *str);

void				ft_listd_push_front(char *str, t_listd **head);

void				ft_listd_push_back(char *str, t_listd **head);

char				*ft_listd_pop(t_listd **head);

char				*ft_listd_peek(t_listd **head);

void				ft_read_to_queue(char *str, t_listd **input);

void				shunting_yard_simple(t_listd **input,
		t_listd **output, t_listd **ops);

t_listd				**shunting_yard(t_listd **input);

void				run_op(int **res, char *s2, char *s1, char *op);

void				execute_op_simple(t_listd **output, int **res);

#endif
