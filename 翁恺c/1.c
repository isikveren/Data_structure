#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%f\n", b / 12);
    printf("%f", ((a + b / 12) * 0.3048));
    return 0;
}