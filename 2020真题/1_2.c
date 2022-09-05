#include <stdio.h>
#include <string.h>
int main()
{

    char a[20] = "hello 2020";
    int i = 0;
    for (; a[i] != '\0'; i++)
    {
    }
    printf("%d %d %d", i, strlen(a), sizeof(a));
    return 0;
}