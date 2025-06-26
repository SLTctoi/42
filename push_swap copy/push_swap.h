// struct (pile a et pile b)
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

typedef struct s_pile
{
	struct s_list	*lst_a;
	struct s_list	*lst_b;
	int	size_a;
	int size_b;
}	t_pile;

// main.c
int list_size(t_list *lst);
t_pile init_pile(int ac, char **av);

// index.c
void    simple_sort(int *lst, int size);
int *sort_tab(t_list *lst, int size);
void    replace_by_index(t_pile *pile);
int get_max_index(t_list *lst);
void    push_b_sort(t_pile *pile);
int in_chunk(t_pile *pile, int min, int max);
void    process_chunk(t_pile *pile, int chunk_min, int chunk_max);
void    push_chunk(t_pile *pile, int chunk_count);
void    sort_chunk(t_pile *pile);

// free.c
void    free_pile(t_pile *pile);
void    free_list(t_list *lst);
void    free_split(char **tab);

// parcing.c
int doublon(t_list *lst);
int already_sort(t_list *lst);
int verif(char **s);
void    parsing(int ac, char **av, t_list **lst_a);


// rules/push.c
void    push_a(t_pile *pile);
void    push_b(t_pile *pile);

// rules/rotate.c
void    rotate(t_list **lst);
void    rotate_a(t_pile *pile);
void    rotate_b(t_pile *pile);
void    rotate_a_and_b(t_pile *pile);

// rules/rrotates.c
void    rrotate(t_list **lst);
void rrotate_a(t_pile *pile);
void rrotate_b(t_pile *pile);
void rrotate_a_and_b(t_pile *pile);

// rules/swap.c
void    swap(t_list **lst);
void    swap_a(t_pile *pile);
void    swap_b(t_pile *pile);
void    swap_a_and_b(t_pile *pile);

// list/list.c
t_list	*lstnew(int content);

// libft
int	ft_atoi(const char *nptr);
void	ft_lstadd_back(t_list **lst, t_list *new);
char	**ft_split(const char *s, char c);

#endif