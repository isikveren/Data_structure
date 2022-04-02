#include<iostream>
#define MaxSize 10
using namespace std;
typedef int ElemType;
struct list {
    ElemType data[MaxSize+1];  //可存放MaxSize
    int length;   //最大值为MaxSize
};
int BinarySearch(list* Tbl, ElemType K);
void addList(list* Tbl,ElemType n);
void createList(list* Tbl);
int main() {
    list* l = new list();
    createList(l);
    for (int i = 1; i <= 9; i++) {
        addList(l, i);
    }
    cout << BinarySearch(l, 10);
    system("pause");
    return 0;
}

int BinarySearch(list* Tbl, ElemType K)  //二分查找算法
{
    int left, mid, right, NoFound = -1;

    left = 1;                   //初始化左边界的值
    right = Tbl->length;        //初始化右边界的值

    while (left <= right) {

        mid = (left + right) / 2;   //计算中间元素坐标 
        if (K > Tbl->data[mid])    left = mid + 1;   //调整左边界
        else if (K < Tbl->data[mid])   right = mid - 1;//调整右边界
        else return mid;        //查找成功返回数据元素的下标
    }
    return NoFound;             //查找失败，返回-1
}

void addList(list* Tbl,ElemType n) {
    if (Tbl->length == MaxSize)  return;
    Tbl->data[++(Tbl->length)] = n;
}

void createList(list* Tbl) {

    Tbl = new list();
    Tbl->length = 0;
    Tbl->data[Tbl->length] = 0;
}