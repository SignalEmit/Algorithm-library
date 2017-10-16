#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
enum letter{A,B,C,D,E,F,G,H};
int answer_x;
int answer_y;
bool JudgeNode[8][8];

struct GoNode
{
	int x;
	int y;
	GoNode(){}
	GoNode(int x_,int y_):x(x_),y(y_)
	{
		JudgeNode[x][y] = true;				//这个节点
	}
	bool MyNextNode(const GoNode *walk,queue<GoNode> &Nodepush)
	{
		for (int i = 0; i < 8; i++)
			if (x + walk[i].x >= 0 && x + walk[i].x <= 7 && y + walk[i].y >= 0 && y + walk[i].y <=7)
			{
				if (answer_x == x + walk[i].x && answer_y == y + walk[i].y)
				{
					return true;
				}
				if (!JudgeNode[x + walk[i].x][y + walk[i].y])
				{
					GoNode s(x + walk[i].x, y + walk[i].y);
					Nodepush.push(s);										//压入链表
				}
			}
		return false;
	}
};
int main()
{
	GoNode walk[8];
	queue<GoNode> father;
	queue<GoNode> son;
	
	string a, b;
	while (cin >> a >> b)
	{
		while (!father.empty())
			father.pop();
		while (!son.empty())
			son.pop();
		answer_x = int(b.at(0) - 'a');							//答案x
		answer_y = int(b.at(1) - '0') - 1;					//答案y

		int x, y;
		x = int(a.at(0) - 'a');							//开始x
		y = int(a.at(1) - '0') - 1;						//开始y

		if (x == answer_x && y == answer_y)
		{
			cout << "To get from " << a << " to " << b << " takes " << 0 << " knight moves." << endl;
			continue;
		}


		walk[0].x = -1; walk[0].y = -2;
		walk[1].x = -1; walk[1].y = 2;
		walk[2].x = 1;  walk[2].y = -2;
		walk[3].x = 1;  walk[3].y = 2;
		walk[4].x = -2; walk[4].y = -1;
		walk[5].x = -2; walk[5].y = 1;
		walk[6].x = 2;  walk[6].y = -1;
		walk[7].x = 2;  walk[7].y = 1;
		memset(JudgeNode, false, sizeof(JudgeNode)); //全部赋false

		GoNode first(x, y);
		father.push(first);
		int sum = 1;
		while (!father.empty())
		{
			if (father.front().MyNextNode(walk, son))
			{
				cout << "To get from " << a << " to " << b << " takes " << sum << " knight moves."<<endl;
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