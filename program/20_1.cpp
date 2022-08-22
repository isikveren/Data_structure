#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int a[] = {3,8,-6,27,9};
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum = sum + a[i]* a[i];
	}
	double sq = sqrt(sum);
	cout << "sum:"<<sum<<"sqrt"<<sq<<endl;
    system("pause");
   return 0;
}