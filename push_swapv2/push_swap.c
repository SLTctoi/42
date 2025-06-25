#include <stdlib.h>
#include <unistd.h>

// STRUCTURE

typedef struct s_piles
{
    int *a;
    int *b;
    int size_a;
    int size_b;
} t_piles;

// UTILS

int ft_atoi(const char *str)
{
    int sign = 1;
    int res = 0;

    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    if (*str == '-' || *str == '+')
        sign = (*(str++) == '-') ? -1 : 1;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*(str++) - '0');
    return (res * sign);
}

void ft_putstr(char *s)
{
    while (*s)
        write(1, s++, 1);
}

// INIT / FREE

int is_duplicate(int *tab, int size, int value)
{
    int i = 0;
    while (i < size)
    {
        if (tab[i] == value)
            return (1);
        i++;
    }
    return (0);
}

void init_piles(t_piles *p, int argc, char **argv)
{
    int i;
    int num;

    p->a = malloc(sizeof(int) * (argc - 1));
    p->b = malloc(sizeof(int) * (argc - 1));
    p->size_a = argc - 1;
    p->size_b = 0;
    if (!p->a || !p->b)
        exit(1);
    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        if (is_duplicate(p->a, i - 1, num))
        {
            ft_putstr("Error\n");
            exit(1);
        }
        p->a[i - 1] = num;
        i++;
    }
}

void free_all(t_piles *pile)
{
    free(pile->a);
    free(pile->b);
}

// OPERATIONS

void swap(int *pile, int size)
{
    int tmp;

    if (size < 2)
        return;
    tmp = pile[0];
    pile[0] = pile[1];
    pile[1] = tmp;
}

void swap_a(t_piles *p, int print)
{
    swap(p->a, p->size_a);
    if (!print)
        write(1, "sa\n", 3);
}

void swap_b(t_piles *p, int print)
{
    swap(p->b, p->size_b);
    if (!print)
        write(1, "sb\n", 3);
}

void push_a(t_piles *p, int print)
{
    int i;

    if (p->size_b == 0)
        return;
    i = p->size_a;
    while (i > 0)
    {
        p->a[i] = p->a[i - 1];
        i--;
    }
    p->a[0] = p->b[0];
    i = 0;
    while (i < p->size_b - 1)
    {
        p->b[i] = p->b[i + 1];
        i++;
    }
    p->size_a++;
    p->size_b--;
    if (!print)
        write(1, "pa\n", 3);
}

void push_b(t_piles *p, int print)
{
    int i;

    if (p->size_a == 0)
        return;
    i = p->size_b;
    while (i > 0)
    {
        p->b[i] = p->b[i - 1];
        i--;
    }
    p->b[0] = p->a[0];
    i = 0;
    while (i < p->size_a - 1)
    {
        p->a[i] = p->a[i + 1];
        i++;
    }
    p->size_b++;
    p->size_a--;
    if (!print)
        write(1, "pb\n", 3);
}

void rotate(int *pile, int size)
{
    int i;
    int tmp;

    if (size < 2)
        return;
    tmp = pile[0];
    i = 0;
    while (i < size - 1)
    {
        pile[i] = pile[i + 1];
        i++;
    }
    pile[i] = tmp;
}

void rotate_a(t_piles *p, int print)
{
    rotate(p->a, p->size_a);
    if (!print)
        write(1, "ra\n", 3);
}

void rotate_b(t_piles *p, int print)
{
    rotate(p->b, p->size_b);
    if (!print)
        write(1, "rb\n", 3);
}

void reverse_rotate(int *pile, int size)
{
    int i;
    int tmp;

    if (size < 2)
        return;
    tmp = pile[size - 1];
    i = size - 1;
    while (i > 0)
    {
        pile[i] = pile[i - 1];
        i--;
    }
    pile[0] = tmp;
}

void reverse_rotate_a(t_piles *p, int print)
{
    reverse_rotate(p->a, p->size_a);
    if (!print)
        write(1, "rra\n", 4);
}

void reverse_rotate_b(t_piles *p, int print)
{
    reverse_rotate(p->b, p->size_b);
    if (!print)
        write(1, "rrb\n", 4);
}

// CHUNKS & SORTING

void temporary_sort(int *pile, int size)
{
    int i, j, tmp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (pile[i] > pile[j])
            {
                tmp = pile[i];
                pile[i] = pile[j];
                pile[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void index_pile(t_piles *pile)
{
    int *sorted;
    int i, j;

    sorted = malloc(sizeof(int) * pile->size_a);
    if (!sorted)
        exit(1);
    i = -1;
    while (++i < pile->size_a)
        sorted[i] = pile->a[i];
    temporary_sort(sorted, pile->size_a);
    i = -1;
    while (++i < pile->size_a)
    {
        j = 0;
        while (j < pile->size_a)
        {
            if (pile->a[i] == sorted[j])
            {
                pile->a[i] = j;
                break;
            }
            j++;
        }
    }
    free(sorted);
}

int get_max_index(int *tab, int size)
{
    int i = 1;
    int index = 0;
    int max = tab[0];

    while (i < size)
    {
        if (tab[i] > max)
        {
            max = tab[i];
            index = i;
        }
        i++;
    }
    return (index);
}

void push_back_sorted(t_piles *pile)
{
    int index;

    while (pile->size_b > 0)
    {
        index = get_max_index(pile->b, pile->size_b);
        if (index <= pile->size_b / 2)
            while (index--)
                rotate_b(pile, 0);
        else
            while (index++ < pile->size_b)
                reverse_rotate_b(pile, 0);
        push_a(pile, 0);
    }
}

int has_in_chunk(t_piles *pile, int min, int max)
{
    int i = 0;

    while (i < pile->size_a)
    {
        if (pile->a[i] >= min && pile->a[i] <= max)
            return (1);
        i++;
    }
    return (0);
}

void push_chunks(t_piles *pile, int chunk_count)
{
    int size = pile->size_a;
    int chunk_size = size / chunk_count;
    int chunk_min = 0;
    int chunk_max = chunk_size;

    while (chunk_min < size)
    {
        while (has_in_chunk(pile, chunk_min, chunk_max))
        {
            int tmp = pile->a[0];
            if (tmp >= chunk_min && tmp <= chunk_max)
            {
                push_b(pile, 0);
                if (pile->b[0] < (chunk_min + chunk_max) / 2)
                    rotate_b(pile, 0);
            }
            else
            {
                rotate_a(pile, 0);
            }
        }

        chunk_min = chunk_max + 1;
        chunk_max += chunk_size;
        if (chunk_max >= size)
            chunk_max = size - 1;
    }
}


void sort_chunks(t_piles *pile)
{
    index_pile(pile);
    if (pile->size_a <= 100)
        push_chunks(pile, 5);
    else
        push_chunks(pile, 11);
    push_back_sorted(pile);
}

// MAIN

int main(int argc, char **argv)
{
    t_piles pile;

    if (argc < 2)
        return (0);
    init_piles(&pile, argc, argv);
    sort_chunks(&pile);
    free_all(&pile);
    return (0);
}
