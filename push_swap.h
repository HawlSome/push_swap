/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:46:41 by varandri          #+#    #+#             */
/*   Updated: 2026/03/06 19:54:38 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	long			index;
	struct s_list	*next;
}	t_list;

typedef struct s_ac_list
{
	char				*name;
	struct s_ac_list	*next;
}	t_ac_list;

typedef struct s_flag_list
{
	int					is_adaptive;
	char				*algo_type;
	struct s_flag_list	*next;
}	t_flag_list;

int			ft_input_verification(char **argv);
int			ft_parse_input(int argc, char **argv, t_list **stack_a,
				char ***parsed);
int			ft_is_str_int(char *str);
int			ft_is_there_str_int(char **tab);
int			ft_is_valid_flag(char *str);
int			ft_is_there_valid_flag(char **tab);
int			ft_is_over_under_flow(char *tab);

float		disorder_metric(t_list *stack_a);

size_t		ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		ft_free_2d(char **tab);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
char		**ft_split(char *s, char c);
char		*ft_strjoin(size_t size, char **strs, char *sep);

t_list		*lst_new(int value);
t_list		*lst_last(t_list *list);
void		lst_add_back(t_list **list, t_list *node);
void		lst_add_front(t_list **list, t_list *node);
size_t		lst_size(t_list *list);
t_list		*ft_find_min_index(t_list *list);
t_list		*ft_find_max_index(t_list *list);

t_ac_list	*lst_ac_new(char *name);
size_t		lst_ac_size(t_ac_list *list);
t_ac_list	*lst_ac_last(t_ac_list *list);
void		lst_ac_add_back(t_ac_list **list, t_ac_list *node);

t_flag_list	*lst_flag_new(char *algo_type);
size_t		lst_flag_size(t_flag_list *list);
t_flag_list	*lst_flag_last(t_flag_list *list);
void		lst_flag_add_back(t_flag_list **list, t_flag_list *node);

void		lst_flag_clear(t_flag_list **list);
void		lst_clear(t_list **list);
void		lst_ac_clear(t_ac_list **list);

void		new_action(t_ac_list	**list, char *name);
void		new_list_value(t_list **list, int value);
void		new_flag(t_flag_list **list, char *algo_type, int is_adaptive);
void		rotate_up(size_t counter, t_list **stack, t_ac_list **act_lst
			, char *action);
void		rotate_down(size_t counter, t_list **stack, t_ac_list **act_lst
			, char *action);
void		ft_ps_few(t_list **stack_a, t_list **stack_b, t_ac_list **actions);

void		ft_push(t_list **from, t_list **to, t_ac_list **act_lst,
				char *act_name);
void		ft_swap(t_list **stack, t_ac_list **act_lst, char *act_name);
void		ft_s_swap(t_list **stack_a, t_list **stack_b, t_ac_list **act_lst);
void		ft_rotate(t_list **stack, t_ac_list **act_lst, char *act_name);
void		ft_r_rotate(t_list **stack_a, t_list **stack_b,
				t_ac_list **act_lst);
void		ft_rev_rotate(t_list **stack, t_ac_list **act_lst, char *act_name);
void		ft_r_rev_rotate(t_list **stack_a, t_list **stack_b,
				t_ac_list **act_lst);

t_list		*ft_find_min_value(t_list *list);
t_list		*ft_find_max_value(t_list *list);
void		ft_ps_simple(t_list **stack_a, t_list **stack_b,
				t_ac_list **act_lst);

size_t		ft_sqrt(size_t nb);
void		index_attribution(t_list **stack);
size_t		ft_range_block(t_list *stack, size_t n_block);
int			ft_find_node_place(t_list *list, t_list *node);
int			is_member_block(t_list *list, size_t min_index, size_t rng_block);
void		ft_ps_medium(t_list **stack_a, t_list **stack_b,
				t_ac_list **act_lst);

size_t		ft_max_bit(t_list *stack_a);
void		ft_ps_complex(t_list **stack_a, t_list **stack_b,
				t_ac_list **act_lst);

void		ft_ps_adaptive(t_list **stack_a, t_list **stack_b,
				t_ac_list **act_list, t_flag_list **flags);

void		ft_benchmark(float disorder, t_ac_list *actions,
				t_flag_list *flags);

int			ft_is_complexity_flag(char *str);
int			ft_is_there_complexity_flag(char **input);
int			ft_is_there_bench_flag(char **input);

void		push_swap(char **input, t_list **stack_a, t_list **stack_b,
				t_ac_list **actions);
#endif
