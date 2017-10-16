#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
long Translate(string s)
{
	long num;
	stringstream ss(s);
	ss >> num;
	return num;
}
int main()
{
	long shopnumber, shopMoney, planDay;
	string Money;
	vector<long> shopMoneyList;
	vector<string> moneyList;
	cin >> shopnumber;
	for (int i = 0; i < shopnumber; i++)
	{
		cin >> shopMoney;
		shopMoneyList.push_back(shopMoney);
	}
	cin >> planDay;
	for (int i = 0; i < planDay; i++)
	{
		cin >> Money;
		moneyList.push_back(Money);
	}

	sort(shopMoneyList.begin(), shopMoneyList.end());

	for (int i = 0; i < moneyList.size(); i++)
	{
		long left = 0, right = shopMoneyList.size() - 1;
		if (shopnumber == 1)
		{
			if (shopMoneyList[0] <= Translate(moneyList[i]))
				cout << 1 << endl;
			else if (shopMoneyList[0] > Translate(moneyList[i]))
				cout << 0 << endl;
			continue;

		}

		if (left + 1 == right)
		{
			if (shopMoneyList[left] == Translate(moneyList[i]))
			{
				cout << left + 1 << endl;
			}
			else if (shopMoneyList[right] == Translate(moneyList[i]))
			{
				cout << right + 1 << endl;
			}
			else if (shopMoneyList[left] > Translate(moneyList[i]) && shopMoneyList[right] > Translate(moneyList[i]))
				cout << left << endl;
			else if (shopMoneyList[left] < Translate(moneyList[i]) && shopMoneyList[right] > Translate(moneyList[i]))
				cout << left + 1 << endl;
			else if (shopMoneyList[left] < Translate(moneyList[i]) && shopMoneyList[right] < Translate(moneyList[i]))
				cout << right + 1 << endl;
			else  if (shopMoneyList[left] < Translate(moneyList[i]) && shopMoneyList[right] > Translate(moneyList[i]))
				cout << right << endl;
			continue;
		}
		while (left < right)
		{
			if (shopMoneyList[(left + right) / 2] < Translate(moneyList[i]))
			{
				left = (left + right) / 2;

			}
			else if (shopMoneyList[(left + right) / 2] > Translate(moneyList[i]))
			{
				right = (left + right) / 2;
			}
			else
			{
				cout << (left + right) / 2 + 1 << endl;
				break;
			}


			if (left + 1 == right)
			{
				if (shopMoneyList[left] == Translate(moneyList[i]))
				{
					cout << left + 1 << endl;
				}
				else if (shopMoneyList[right] == Translate(moneyList[i]))
				{
					cout << right + 1 << endl;
				}
				else if (shopMoneyList[left] > Translate(moneyList[i]) && shopMoneyList[right] > Translate(moneyList[i]))
					cout << left << endl;
				else if (shopMoneyList[left] < Translate(moneyList[i]) && shopMoneyList[right] > Translate(moneyList[i]))
					cout << left + 1 << endl;
				else if (shopMoneyList[left] < Translate(moneyList[i]) && shopMoneyList[right] < Translate(moneyList[i]))
					cout << right + 1 << endl;
				else  if (shopMoneyList[left] < Translate(moneyList[i]) && shopMoneyList[right] > Translate(moneyList[i]))
					cout << right << endl;
				break;
			}

		}
		
	}
}