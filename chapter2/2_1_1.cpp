#include <iostream>
using namespace std;
#define Max 50
struct SqList
{
    int a[Max] = {3,1,2};
    int length = 3;
};
int listdelete(SqList *s, int &ele)
{
    if (s->length == 0)
    {
        return false;
    }
    int min = s->a[0];
    int flag = 0;
    for (int i = 1; i < s->length; i++)
    {
        if (s->a[i] < min)
        {
            min = s->a[i];
            flag = i;
        }
    }
    ele = s->a[flag];
    s->a[flag] = s->a[s->length - 1];
    return s->a[flag];
}
void printsql(SqList &s)
{

    for (int i = 0; i < s.length; i++)
    {
        cout << s.a[i] << " ";
    }
}

int main()
{
    SqList s;
    int x;
    printsql(s);
    if (listdelete(&s, x))
    {
        cout << "最小元素K = " << x << endl;
    }
    else
    {
        cout << "错误";
    }
    printsql(s);
    return 0;
}