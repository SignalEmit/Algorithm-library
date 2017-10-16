#include<iostream>
using namespace std;
bool JudgeNumber(int Number)
{
	int a[10];
	for(int i=0; ;i++)
	{
		if (Number != 0)
		{
			a[i] = Number % 10;
			Number = Number / 10;
		}
		else
			break;
	}

	for (int i = 0; i < 5; i++)
		for (int o = i+1; o < 5; o++)
			if (a[i] == a[o])
				return false;
	return true;
}
int main()
{
	cout << "请输入要输入的数：";
	int n;
	cin >> n;
	for (int i = 1234; i <= 9999; i++)
		if (i % 10 && JudgeNumber(i) && i*n <= 98765)
			if (JudgeNumber(i*n))
				cout << i*n<<" ";
			
	system("pause");
}