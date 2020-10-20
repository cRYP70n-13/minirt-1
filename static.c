#include <stdio.h>

void pizza (void)
{
    static int t;
    printf("%d\n", t);
    t++;
}

int main ()
{
    pizza();
    pizza();
    pizza();
    return (0);
}