#include<iostream>
using namespace std;
int fastsum(int n)
{
	if (n == 1)
		return 1;
	if(n % 2 == 1)
		return n + fastsum(n - 1);
	return 2 * fastsum(n / 2) + n / 2 * n / 2;
}
int main()
{
	cout << fastsum(101);
	system("pause");
}