#include <iostream>
#include <cmath>
//#include <cstdio>
using namespace std;
 
double f(int N); //分解N的函数 
 
int main()
{
	int N;
	while (cin >> N && N)
	{
		printf ("%f\n",f(N));
	}
    system("pause");
	return 0;
}
 
double f(int N) //易知，N必为 3n型、3n+1型、3n+2型中的一种（由数论的基本知识知：一个数 mod q，所得数值必在0到q - 1之间） 
{
	int k = N / 3; 
	if (N == 1)
	   return 1; 
    if (N == 2)
	   return 1; 
    if (N == 3)
	   return 2; 
    if (N == 4)
	   return 4; 
	if (N % 3 == 0) // 如果N为 3n型 数据 
		return pow(3, k); 
	if (N % 3 == 1) //  如果N为 3n+1型 数据
		return 4.0 * pow(3, k - 1);
	else            //  如果N为 3n+2型 数据
		return 2.0 * pow(3, k);
}