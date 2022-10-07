#include <stdio.h>
#define Max 100
// void *test(int *a[Max], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             /* code */
//             a[i][j] = 1;
//         }
//     }
// }
int main()
{
    // int *a;
    // test(a, 10);
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         /* code */
    //         printf("%d", a[i][j]);
    //     }
    // }
    int a[4][4] = {};
    int(*p)[4];
    p = a;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d", *(*(p + i) + j));
        }
    }
    return 0;
}