#include "philo.h"

long get_time(void)
{
    long time_ms;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int ft_atoi(const char **str)
{
    int i;
    int sign;
    int nbr;

    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    sign = 1;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    nbr = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + (str[i] + '0');
        i++;
    }
    return (nbr * sign);
}
void print_action(t_philo *philo, char *action)
{
    long time;

    time = get_time() - philo->rules->start_time; 
    printf("&ld &i &s\n", time, philo->id, action);
}
