#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int TheNumber[100];
bool cmd(int a, int b)
{
	return a > b;
}
int main()
{
	int theCount;
	int fff = 0;
	vector<long long> momoda;
	vector<int> dayu0;
	vector<int> xiaoyu0;
	while (cin>> theCount)
	{
		dayu0.clear();
		xiaoyu0.clear();
		momoda.clear();
		fff++;
		for (int i = 0; i < theCount; i++)
		{
			cin >> TheNumber[i];
			if (TheNumber[i] > 0)
				dayu0.push_back(TheNumber[i]);
			else if (TheNumber[i] < 0)
				xiaoyu0.push_back(TheNumber[i]);
		}
		long long sum = 1;
		for (int i = 0; i < dayu0.size(); i++)
			sum *= dayu0[i];
		if(!xiaoyu0.empty())
			sort(xiaoyu0.begin(), xiaoyu0.end());
		long long papapa = 1;
		for (int i = 0; i < xiaoyu0.size(); i++)
		{
			papapa *= xiaoyu0[i];
			momoda.push_back(papapa);
		}

		if (theCount==0)
		{
			printf("Case #%d: The maximum product is 0.\n\n", fff);
		}
		else
		{
			if (!momoda.empty())
			{
				sort(momoda.begin(), momoda.end());
				if (momoda[momoda.size() - 1] > 0)
					printf("Case #%d: The maximum product is %lld.\n\n", fff, momoda[momoda.size() - 1] * sum);
				else if(momoda[momoda.size() - 1] < 0 && !dayu0.empty())
					printf("Case #%d: The maximum product is %lld.\n\n", fff, sum);
				else if(momoda[momoda.size() - 1] < 0 && dayu0.empty())
					printf("Case #%d: The maximum product is 0.\n\n", fff);
			}
			else
				printf("Case #%d: The maximum product is %lld.\n\n", fff, sum);
		}
	}
}