#include<iostream>
#define N 100
using namespace std;

int main() {
	int count = 0;
	for(int j = 0;j<10;j++){
	char s[N];
	cin>>s;
	//cout << sizeof(s) << endl;
	int sum = 0;
	for (int i = 0; s[i]!='\0'; i++)
	{
		sum = sum + s[i];
		//cout << int(s[i]) << endl;
	}
	count = count + sum;
	}
	cout << count << endl;

	return 0;
}