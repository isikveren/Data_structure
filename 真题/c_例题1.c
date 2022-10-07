#include <stdio.h>

int main()
{
    void f(int a);
    f(3);
    return 0;
}

void f(int a)
{
    int i;
    if (a != 0)
    {
        f(a - 1);
        for (i = 1; i <= a; i++)
        {
            printf("%d", a);
        }
        printf("\n");
    }
}