#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int size;
	int a[20 * 4];
	vector<int> jilu;
	cin >> size;

	if (size % 2 == 1)
	{
		cout << "´íÎó";
		return 0;
	}

	
	for (int i = 0; i < size; i++)
		cin >> a[i];
	sort(a, a+size);


	int w = size / 2;
	for (int i = 0; i < w; i++)
	{
		jilu.push_back(a[i] + a[size - i - 1]);
	}

	for(int i=0;i<w;i++)
		if (jilu[0] != jilu[i])
		{
			cout << "´íÎó£¡£¡£¡";
			system("pause");
			return 0;
		}
	cout << "ÕæÈ·";

	system("pause");
}