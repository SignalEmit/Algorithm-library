#include<iostream>
#include<string>
using namespace std;
int L, n;
bool is_judge = false;
string str = "";
int jishuqi = 1;
bool Judge(string A) 
{ 
	for (int i = 1; i <= A.size()/2; i++)
	{
		if (A.size() - 2 * i < 0)
			break;
		if (A.substr(A.size() - i) == A.substr(A.size() - 2 * i, i))
			return false;
	}
	return true;
}
void digui()
{
	for (int i = 65; i < 65 + L; i++)
	{
		if (Judge(str + char(i)))
		{
			str = str + char(i);
			jishuqi++;
			if (jishuqi == n)
			{
				int count = 0;
				for (int i = 0; i < str.size(); i++)
				{
					if (count % 4 == 0 && count != 0)
						cout << " ";
					cout << str[i];
					count++;
				}
				cout << endl;
				cout << str.size() << endl;
				is_judge = true;
				break;
			}
			if (is_judge)
				return;
			digui();
		}
	}
	str.erase(str.end() - 1);
}
int main()
{
	while (cin >> n >> L && n || L)
	{
		if (n == 1)
		{
			cout << "A" << endl;
			continue;
		}
		is_judge = false;
		jishuqi = 1;
		str = "A";
		digui();
	}
	return 0;
}