#include<iostream>
using namespace std;
int dugui(int n)
{
	if (n == 1)
		return 1;
	else
		return n + dugui(n - 1);
}
int main()
{
	cout << dugui(100);
	system("pause");
}