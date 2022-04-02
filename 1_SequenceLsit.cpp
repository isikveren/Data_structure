#include <iostream> //顺序表
#define MAXSIZE 20
using namespace std;
struct sqList
{
    int data[MAXSIZE] = {0};
    int length;
    // sqList(){
    //     data[0] = 0;
    // }
};
int GetElem(sqList l, int i);             //获取元素
bool ListInsert(sqList *l, int i, int e); //插入元素
bool ListDelete(sqList *l, int i, int *e);
void PrintList(sqList *l); //打印顺序表
int main()
{
    sqList *a = new sqList();
    ListInsert(a, 1, 1);
    ListInsert(a, 1, 2);
    ListInsert(a, 1, 3);
    PrintList(a);
    cout << GetElem(*a, 2) << endl;
    int x = 1;
    ListDelete(a, 3, &x);
    cout << "x = " << x << endl;
    // cout<<GetElem(*a,2)<<endl;
    PrintList(a);
    system("pause");
    return 0;
}

int GetElem(sqList l, int i)
{ //取顺序表第i个元素的值
    if (l.length == 0 || i < 1 || i > l.length)
        return 0;
    int e = l.data[i - 1];
    return e;
}

bool ListInsert(sqList *l, int i, int e)
{
    if (l->length == MAXSIZE)
        return 0;
    if (i < 1 || i > l->length + 1)
        return 0;
    if (i <= l->length)
    {
        for (int k = l->length - 1; k >= i - 1; k--)
            l->data[k + 1] = l->data[k];
    }
    l->data[i - 1] = e;
    l->length++;

    return 1;
}

void PrintList(sqList *l)
{

    for (int i = 0; i < l->length; i++)
    {
        if (i == l->length - 1)
            cout << l->data[i] << endl;
        else
            cout << l->data[i] << " ";
    }
}

bool ListDelete(sqList *l, int i, int *e)
{
    if (l->length == 0 || i < 1 || i > l->length)
        return 0;
    *e = l->data[i - 1];
    if (i < l->length)
    {
        for (int k = i - 1; k < l->length; k++)
        {
            l->data[k] = l->data[k + 1];
        }
    }

    l->length--;
    return 1;
}