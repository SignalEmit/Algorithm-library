#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int **a;
	a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[i];
		for (int j = 0; j < i+1; j++)
		{
			cin >> a[i][j];
		}
	}

	
	int *p;
	int *q;

	for (int i = n-1; i >0; i--)
	{
		p = a[i];			//指向最后
		q = a[i - 1];
		for (int j = 0; j < i; j++)
		{
			q[j] = max(p[j], p[j + 1]) + q[j];
		}
	}
	cout << a[0][0];
	system("pause");
}