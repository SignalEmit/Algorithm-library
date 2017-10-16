#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string judge(char n, string s)
{
	switch (n)
	{
	case '2': {s += '2'; }break;
	case '3': {s += '3'; }break;
	case '4': {s += "223"; }break;
	case '5': {s += '5'; }break;
	case '6': {s += "35"; }break;
	case '7': {s += '7'; }break;
	case '8': {s += "2227"; }break;
	case '9': {s += "2337"; }break;
	default:
		break;
	}
	return s;
}
bool panudan(int a, int b)
{
	return a > b;
}
int main()
{
	string s, newstring = "";
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		newstring = judge(s[i], newstring);
	}
	int *a;
	a = new int[newstring.size()];
	for (int i = 0; i < newstring.size(); i++)
	{
		a[i] = (int)(newstring[i] - '0');
	}
	sort(a, a + newstring.size(), panudan);
	for (int i = 0; i < newstring.size(); i++)
		cout << a[i];
}
