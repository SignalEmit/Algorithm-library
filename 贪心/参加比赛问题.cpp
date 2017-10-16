#include<iostream>
#include<algorithm>
using namespace std;
const int Max_people = 2000;
int main()
{
	int peole[Max_people];

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> peole[i];
		peole[i] += k;
	}
	sort(peole, peole + n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (peole[i] <= 5)
			sum++;
	sum /= 3;
	cout << sum << endl;
	return 0;
}