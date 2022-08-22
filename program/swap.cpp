#include<iostream>

using namespace std;

void swap1(int &a,int &b);
void swap2(int a,int b);
int main(){
    int x1 = 1,y1 = 2;
    int x2 = 1,y2 = 2;
    swap1(x1,y1);
    cout<< x1<<" "<< y1<<endl;
   
    swap(x2,y2);
    cout<< x2<<" "<< y2<<endl;
    system("pause");
    return 0;
}


void swap1(int &a,int &b){

    int tmp = a;
    a = b;
    b = tmp;
}
void swap2(int *a,int *b){

    int tmp = *a;
    *a =  *b;
    *b = tmp;
}