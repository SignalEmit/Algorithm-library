#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	long n, k;
	cin >> n >> k;
	vector<int> numberVector;
	vector<int> newList;
	vector<int> gogo;
	for (int i = 1; i <= n; i++)
		numberVector.push_back(i);

	if (k == 1)
	{
		for (int i = 0; i < n; i++)
			cout << numberVector[i]<<" ";
		return 0;
	}
	else if (k == n - 1)
	{
		for (int i = 0; i < n / 2; i++)
		{
			newList.push_back(numberVector[n - i - 1]);
			newList.push_back(numberVector[i]);
		}
		if (n % 2 == 1)
			newList.push_back((numberVector[n - 1] + numberVector[0]) / 2);

		for (int i = 0; i < newList.size(); i++)
			cout << newList[i] << " ";
		return 0; 
	}
	else if ((k >= 0 && k < n) && (k < n))
	{
		int f;
		if (k % 2 == 1)
			f = k + 1;
		else
			f = k;
		for (int i = 0; i < f/2; i++)
		{
			newList.push_back(numberVector[numberVector.size()-1]);
			numberVector.erase(numberVector.end() - 1);
			newList.push_back(numberVector[0]);
			numberVector.erase(numberVector.begin());
		}
		if (k % 2 == 1)				//²»ÊÇÅ¼Êý
		{
			numberVector.insert(numberVector.begin(), newList[newList.size() - 1]);
			newList.erase(newList.end() - 1);
			for (int i = 0; i < newList.size(); i++)
				cout << newList[i]<<" ";
			for (int i = numberVector.size() - 1; i >= 0; i--)
				cout << numberVector[i] << " ";
		}
		else
		{
			for (int i = 0; i < newList.size(); i++)
				cout << newList[i] << " ";
			for (int i = 0; i < numberVector.size(); i++)
			{
				cout << numberVector[i] << " ";
			}
		}
	}
}