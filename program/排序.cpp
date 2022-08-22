#include<iostream>
#define Max 10
using namespace std;
typedef int ElemType;

//冒泡排序 插入排序 希尔排序 选择排序
void print_array(ElemType A[], int N);
void Bubble_sort(ElemType A[], int N);
void insertsort(ElemType* r, int N);
void shell_sort(ElemType A[], int N);
void selection_sort(ElemType A[], int N);
void swap(ElemType* a, ElemType* b);

ElemType Median3(ElemType A[], int Left, int Right);
void Qsort(ElemType A[], int Left, int Right);
void QuickSort(ElemType A[], int N);

//折半插入算法
void BinaryInsertion_sort(ElemType A[], int N);

int main() {                        //测试
    int s[Max] = { 4,3,2,1,6,9,8,7,10,11 };
    //Bubble_sort(s, Max);
    //insertsort(s, Max);
    //shell_sort(s, Max);
    //selection_sort(s, Max);
    //QuickSort(s, Max);
    BinaryInsertion_sort(s, Max);
    print_array(s, Max);
    
    return 0;
}


void Bubble_sort(ElemType A[], int N) {             //冒泡排序 
    for (int P = N - 1; P >= 0; P--) {
        int flag = 0;                               //flag表示每次循环交换次数
        for (int i = 0; i < P; i++) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                flag++;
            }
        }
        //cout << flag << endl;
        if (flag == 0)   break;                     
    }
    cout << endl << "      ----------冒泡排序--------" << endl;
}
void print_array(ElemType A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << endl;
    }
}

void insertsort(ElemType* r,int N)
{
    ElemType tmp;
    //直接插入排序
    int i, P;
    for (P = 1; P < N; P++)
    {
        tmp = r[P];
        for (i = P; r[i-1] > tmp&&i>0; i--)
            r[i] = r[i-1];
        r[i] = tmp;
    }
   
    cout << endl << "      ----------直接插入排序--------" << endl;
}

void shell_sort(ElemType A[], int N)
{
    int i, P,tmp;
    for (int D = N / 2; D > 0; D = D / 2) {
        for (P = D; P < N; P++) {
            tmp = A[P];
            for (i = P; i >0 && A[i - D] > tmp; i = i - D)
                A[i] = A[i - D];
             A[i] = tmp;
        }   
    }
    cout << endl << "      ----------希尔排序--------" << endl;
}

void selection_sort(ElemType A[], int N) {
    int i,j,k;
    for (i = 0; i < N; i++) {
        k = i;
        for (j = i+1; j < N; j++) {
            if (A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
    cout << endl << "      ----------选择排序--------" << endl;
}

void swap(ElemType* a, ElemType* b)
{
    ElemType t = *a;
    *a = *b;
    *b = t;
}


/* 快速排序 */

ElemType Median3(ElemType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if (A[Left] > A[Center])
        swap(A[Left], A[Center]);
    if (A[Left] > A[Right])
        swap(A[Left], A[Right]);
    if (A[Center] > A[Right])
        swap(A[Center], A[Right]);
    /* 此时A[Left] <= A[Center] <= A[Right] */
    swap(A[Center], A[Right - 1]); /* 将基准Pivot藏到右边*/
    /* 只需要考虑A[Left+1] … A[Right-2] */
    return  A[Right - 1];  /* 返回基准Pivot */
}

void Qsort(ElemType A[], int Left, int Right)
{ /* 核心递归函数 */
    int Pivot, Cutoff, Low, High;
    Cutoff = 100;
    if (Cutoff <= Right - Left) { /* 如果序列元素充分多，进入快排 */
        Pivot = Median3(A, Left, Right); /* 选基准 */
        Low = Left; High = Right - 1;
        while (1) { /*将序列中比基准小的移到基准左边，大的移到右边*/
            while (A[++Low] < Pivot);
            while (A[--High] > Pivot);
            if (Low < High) swap(A[Low], A[High]);
            else break;
        }
        swap(A[Low], A[Right - 1]);   /* 将基准换到正确的位置 */
        Qsort(A, Left, Low - 1);    /* 递归解决左边 */
        Qsort(A, Low + 1, Right);   /* 递归解决右边 */
    }
    else insertsort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 */
}

void QuickSort(ElemType A[], int N)
{ /* 统一接口 */
    Qsort(A, 0, N - 1);
    cout << endl << "      ----------快速排序--------" << endl;
}

void BinaryInsertion_sort(ElemType A[], int N)
{   
    int i, j, mid, low, high,tmp;
    for (i = 1; i < N; i++) {
        tmp = A[i];
        low = 0;
        high = i-1 ;
        while (high>=low) {
            //cout << high;
            mid = (low + high) / 2;
            if (A[mid] > tmp) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i; j > low; j--) {
            A[j] = A[j - 1];
        }
        A[low] = tmp;

    }
    cout << endl << "      ----------折半插入排序--------" << endl;
}
