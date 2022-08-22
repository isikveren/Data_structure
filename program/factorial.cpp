#include<iostream>

using namespace std;
int factorial_result(int n);
int main(){

    cout<<factorial_result(4);
    system("pause");
    return 0;
}

int factorial_result(int n){
    if(n == 1)  return 1;
    else    return   n*factorial_result(n-1);
}