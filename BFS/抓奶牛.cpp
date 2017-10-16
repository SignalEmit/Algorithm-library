#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const int MAX = 1e5+1;
int cow;
int GOGOGO[] = { -1,1,2 };
struct Node
{
	int x;
	Node(int x_,bool *judge):x(x_)
	{
		judge[x] = true;
	}
	bool MyNextNode(queue<Node> &Nodepush,bool *judge)
	{
		for (int i = 0; i < 3; i++)
			if (abs(GOGOGO[i]) == 1)
			{
				if (x + GOGOGO[i] >= 0 && x + GOGOGO[i] <= 1e5)
				{
					if (cow == x)
					{
						return true;
					}
					if (!judge[x + GOGOGO[i]])
					{
						Node s(x + GOGOGO[i], judge);
						Nodepush.push(s);										//压入链表
					}
				}
			}
			else
			{
				if (GOGOGO[i]*x >= 0 && x*GOGOGO[i] <= 1e5)
				{
					if (cow == x)
					{
						return true;
					}
					if (!judge[GOGOGO[i] * x])
					{
						Node s(GOGOGO[i] * x, judge);
						Nodepush.push(s);										//压入链表
					}
				}
			}
		return false;
	}
};
int main()
{
	int peple;
	bool Judge[MAX];
	queue<Node> father;
	queue<Node> son;

	while (cin >> peple >> cow)
	{
		while (!father.empty())
			father.pop();
		while (!son.empty())
			son.pop();
		memset(Judge, false, sizeof(Judge));
		Node s(peple, Judge);
		father.push(s);

		int sum = 1;
		while (!father.empty())
		{
			if (father.front().MyNextNode(son,Judge))
			{
				cout <<sum-1<< endl;
				break;
			}
			father.pop();
			if (father.size() == 0)
			{
				sum++;
				while (!son.empty())
				{
					father.push(son.front());
					son.pop();
				}
			}
		}
	}
}