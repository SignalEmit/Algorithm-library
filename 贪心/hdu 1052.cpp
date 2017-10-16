#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 1000+10;
bool bangbanji(int a, int b)
{
	return a > b;
}
int main()
{
	int tianji[MAX],King[MAX];
	int size;
	cin >> size;
	while (size)
	{
		for (int i = 0; i < size; i++)
			cin >> tianji[i];
		for (int i = 0; i < size; i++)
			cin >> King[i];
		sort(tianji, tianji + size, bangbanji);
		sort(King, King + size, bangbanji);

		int count=0;
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			for (; j <size; j++)
			{
				if (tianji[i] > King[j])
				{
					j++;
					count++;
					break;
				}
				else if (tianji[i] == King[j])
				{
					count--;

				}
				else
				{
					count--;
				}
			}
		}
		cout << 200 * count;
		cin >> size;
	}
	return 0;
}