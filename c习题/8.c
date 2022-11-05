#include <stdio.h>

struct st
{
    int n;
    struct st *next;
};
int main()
{
    static struct st a[2] = {5, &a[1], 7, &a[2], 9, NULL}, *p;
    p = &a[0];

    printf("%d\n", ++p->n);
    printf("%d\n", p->n);
    return 0;
}