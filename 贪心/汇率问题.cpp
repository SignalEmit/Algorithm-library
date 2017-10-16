#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct number
{
	char c;
	int weizhi;
	number(char c_,int weizhi_):c(c_),weizhi(weizhi_){}
};
int main()
{
	string s;
	cin >> s;		
	int z=0;
	vector<number> newNumber;
	for (int i = 0; i < s.size(); i++)
	{
		if (int(s[i]) % 2 == 0)
		{
			number ppp(s[i], i);
			newNumber.push_back(ppp);
		}
	}
	if (newNumber.size() == 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < newNumber.size(); i++)
	{
		if (int(newNumber[i].c)<int(s[s.size()-1]))
		{
			char w = s[newNumber[i].weizhi];
			s[newNumber[i].weizhi] = s[s.size() - 1];
			s[s.size() - 1] = w;
			cout << s;
			return 0;
		}
		if (i == newNumber.size() - 1)
		{
			char w = s[newNumber[i].weizhi];
			s[newNumber[i].weizhi] = s[s.size() - 1];
			s[s.size() - 1] = w;
			cout << s;
			return 0;
		}
	}
}