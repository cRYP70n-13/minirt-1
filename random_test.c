#include <stdio.h>
#include "math.h"
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

static long digitlen(long n)
{
    long i;

    i = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        i++;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *ft_itoa(long n)
{
    long m;
    char *str;
    long nb;

    nb = n;
    m = digitlen(n);
    if (!(str = (char *)malloc(m + 1)))
        return (NULL);
    if (nb == 0)
    {
        str[0] = 0 + '0';
    }
    if (nb < 0)
    {
        nb *= -1;
        str[0] = '-';
    }
    while (nb != 0)
    {
        str[m - 1] = nb % 10 + '0';
        nb /= 10;
        m--;
    }
    str[digitlen(n)] = '\0';
    return (str);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *sub;

    i = 0;
    if (s == NULL)
        return (NULL);
    if (ft_strlen(s) < start)
        len = 0;
    sub = (char *)malloc((len + 1) * sizeof(char));
    if (!sub)
        return (NULL);
    while (len--)
    {
        sub[i] = s[start];
        i++;
        start++;
    }
    sub[i] = '\0';
    return (sub);
}

int generate_r_number(int seed)
{
    static int _number;
    long number;
    char *nums;
    char *sub_nums;

    if (seed > 0)
        _number = seed;
    number = _number;
    number = pow(number, 2);
    nums = ft_itoa(number);
    sub_nums = ft_substr(nums, 3, 6);
    _number = atol (sub_nums);
    free (nums);
    free (sub_nums);
    return (_number);
}

int main()
{
    long number = generate_r_number (675248);
    printf ("%ld\n", number);
    number = generate_r_number (0);
    printf ("%ld\n", number);
    number = generate_r_number (0);
    printf ("%ld\n", number);
    number = generate_r_number (0);
    printf ("%ld\n", number);
    return (0);
}