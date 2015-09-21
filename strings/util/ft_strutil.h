/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutil.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 18:23:11 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 13:33:46 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUTIL_H
# define FT_STRUTIL_H
# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(char *str);

char	*ft_strdup_between(char *start, char *end);

int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2);

int		ft_atoi(char *str);

char	*ft_itoa(char *str);

#endif
