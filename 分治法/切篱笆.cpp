/**********«–¿È∞ *****************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> hedge;
int fenzhi(int star_, int end_)
{
	if (star_ == end_)
	{
		int count = 0;
		for (int i = star_-1; i >= 0; i--)
			if (hedge[i] >= hedge[star_])
				count++;
			else
				break;
		for (int i = end_+1; i < hedge.size(); i++)
			if (hedge[i] >= hedge[star_])
				count++;
			else
				break;
		return (count + 1)*hedge[star_];
	}
	if (star_ + 1 == end_)
	{
		return max(fenzhi(star_, star_), fenzhi(end_, end_));
	}
	else
	{
		return max(fenzhi(star_, (end_ +star_)/2),fenzhi( (star_+end_) / 2, end_));
	}
}
int main()
{
	int N,m,Max_size;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		hedge.clear();
		cin >> Max_size;
		for (int o = 0; o < Max_size; o++)
		{
			cin >> m;
			hedge.push_back(m);
		}
		cout << fenzhi(0, hedge.size() - 1)<<endl;
	}
}
