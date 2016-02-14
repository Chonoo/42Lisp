/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lisp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 22:23:38 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/14 19:44:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISP_H
# define FT_LISP_H
# define GC_LOCK_CLEAN 42
# define GC_INC(val) (val->refcnt += 1)
# define GC_DEC(val) (val->refcnt -= 1)
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# define ERR_NO_MEM 1
# define ERR_WRONG_TYPE 2
# define ERR_UNIMPLEMENTED 3
# define ERR_NOT_DEFINED 4
# define ERR_IS_NULL 5

typedef struct s_lvar	t_lvar;

/*
** ## Garbage Collector ##
*/

typedef struct			s_lvar_generation
{
	int					length;
	t_lvar				*start;
	t_lvar				*end;
}						t_lvar_generation;

typedef struct			s_gc_mem
{
	int					lock;
	pthread_t			thread;
	t_lvar_generation	gen1;
	t_lvar_generation	gen2;
	t_lvar_generation	gen3;
}						t_gc_mem;

extern t_gc_mem			g_gc_mem;

int						gc_lock(pthread_t thread);

int						gc_unlock(pthread_t thread);

void					gc_add(t_lvar *var);

/*
**  ## Integers ##
*/

typedef enum			e_inttype
{
	T_INT
}						t_inttype;

typedef union			u_intp
{
	long				*intp;
}						t_intp;

typedef struct			s_int
{
	t_inttype			inttype;
	t_intp				*val;
}						t_int;

t_int					*int_new(void);

t_int					*int_add(t_int *a, t_int *b);

t_int					*int_sub(t_int *a, t_int *b);

t_int					*int_mul(t_int *a, t_int *b);

t_int					*int_div(t_int *a, t_int *b);

void					int_puts(t_int *ptr);

/*
**  ## Strings ##
*/

/*
**  ## LLST ##
**  (lisp list type)
*/

typedef struct			s_llst
{
	struct s_llst		*next;
	t_lvar				*val;
}						t_llst;

t_llst					*llst_new(void);

t_lvar					*llst_car(t_llst *lst, int *errn);

t_llst					*llst_cdr(t_llst *lst, int *errn);

t_llst					*llst_cons(t_lvar *var, t_llst *lst, int *errn);

/*
**  ## System functions ##
*/

typedef struct			s_sysfn
{
	int					varcnt;
	t_lvar				*(*fn)();
}						t_sysfn;

t_lvar					*sys_call(t_lvar **arr, t_sysfn *fn);

/*
**  ## Lvar ##
*/

typedef enum			e_ltype
{
	T_NULLP,
	T_INTP,
	T_LLSTP,
	T_SYSFNP
}						t_ltype;

typedef union			u_lptr
{
	t_int				*intp;
	t_llst				*llstp;
	t_sysfn				*sysfnp;
}						t_lptr;

typedef struct			s_lvar
{
	int					refcnt;
	t_ltype				type;
	t_lvar				*gc_next;
	t_lptr				*val;
}						t_lvar;

t_lvar					*lvar_new(void);

t_lvar					*lvar_new_int(char *str, int *errn);

t_lvar					*lvar_new_llst(t_lvar *var, int *errn);

t_lvar					*lvar_add(t_lvar *a, t_lvar *b, int *errn);

t_lvar					*lvar_cons(t_lvar *a, t_lvar *b, int *errn);

void					lvar_puts(t_lvar *var);

int						ltype_is_num(t_lvar *var);

void					error_raise(int *errn, int errint);

void					error_print_stack(char *str);

/*
** ## Name Spaces ##
*/

typedef struct			s_nshi
{
	char				*name;
	t_lvar				*value;
	struct s_nshi		*next;
}						t_nshi;

t_nshi					*nshash_new_bucket(char *str, t_lvar *var);

typedef struct			s_nshash
{
	int					(*hash)(char *);
	t_lvar				*(*get)(struct s_nshash *self, char *, int *);
	void				(*add)(struct s_nshash *self, char *, t_lvar *, int *);
	t_nshi				**buckets;
	struct s_nshash		*parent;
}						t_nshash;

t_nshash				*ns_global_new(int *errn);

/*
** If this function crashes, the interpreter kind of has to exit.
** Thus error handling is done the C way
*/

int						sys_setup(t_nshash *global);

#endif
