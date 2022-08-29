
//键盘输入AhaMa Aha<CR> (<CR>表示回车)运行结果为
#include <stdio.h>

int main()
{
    char s[80], c = 'a';
    int i = 0;
    scanf("%s", s);
    while (s[i] != '\0')
    {
        if (s[i] == c)
            s[i] = s[i] - 32;
        else if (s[i] == c - 32)
            s[i] = s[i] + 32;
        i++;
    }
    puts(s);
    return 0;
}