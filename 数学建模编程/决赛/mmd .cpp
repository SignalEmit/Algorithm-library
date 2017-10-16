#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct aaa
{
	int a;
};
bool cmd(const aaa & a, const aaa & b)
{
	return a.a < b.a;
}
int main()
{
	vector<aaa> a;
	aaa ss;
	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;

	ss.a = rand() % 60;

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	ss.a = rand() % 60;
	a.push_back(ss);

	a.push_back(ss);
	sort(a.begin(),a.end(),cmd);
	cout << endl;
}