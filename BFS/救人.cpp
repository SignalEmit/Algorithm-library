#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<list>
using namespace std;
int answer_x;
int answer_y;
int x_row, y_span;
int sum = 1;
bool is_find = false;
struct chuizi
{
	int x;
	int y;
	chuizi(int x_,int y_,bool **judge):x(x_),y(y_)
	{
		judge[x][y] = true;
	}
};
list<chuizi> wenyishou;
list<chuizi> now;
struct GoNode
{
	int x;
	int y;
	bool is_first;
	GoNode() {}
	GoNode(int x_, int y_, bool **judge) :x(x_), y(y_)
	{
	
		judge[x][y] = true;				//这个节点
		is_first = true;
	}
	bool MyNextNode(const GoNode *walk, queue<GoNode> &Nodepush, bool **judge, char **map)
	{
		for (int i = 0; i < 4; i++)
			if (x + walk[i].x >= 0 && x + walk[i].x < x_row && y + walk[i].y >= 0 && y + walk[i].y < y_span && map[x + walk[i].x][y + walk[i].y] != '#')
			{
				if (answer_x == x + walk[i].x && answer_y == y + walk[i].y)
				{
			
					return true;
				}
			
				if (!judge[x + walk[i].x][y + walk[i].y])
				{
				
					if (map[x + walk[i].x][y + walk[i].y] == 'x')
					{
						chuizi s(x + walk[i].x, y + walk[i].y,judge);								//压入链表
						now.push_back(s);
					}
					else
					{
						GoNode s(x + walk[i].x, y + walk[i].y, judge);
						Nodepush.push(s);
					}
				}
			}
		for (auto i = wenyishou.begin(); i != wenyishou.end(); i++)
		{
			GoNode s(i->x, i->y, judge);
			Nodepush.push(s);
		}
		wenyishou.clear();
		for (auto i = now.begin(); i != now.end(); i++)
		{
			wenyishou.push_back(*i);
		}
		now.clear();
		return false;
	}
};
int main()
{
	GoNode walk[4];
	queue<GoNode> father;
	queue<GoNode> son;
	bool **judge;
	char **map;

	int people_x, people_y;
	while (cin >> y_span >> x_row)
	{
		sum = 1;
		wenyishou.clear();
		now.clear();
		while (!father.empty())
			father.pop();
		while (!son.empty())
			son.pop();


		judge = new bool *[x_row];
		map = new char *[x_row];
		for (int i = 0; i < x_row; i++)
		{
			judge[i] = new bool[y_span];
			map[i] = new char[y_span];
		}


		walk[0].x = 0; walk[0].y = -1;
		walk[1].x = 0; walk[1].y = 1;
		walk[2].x = 1;  walk[2].y = 0;
		walk[3].x = -1;  walk[3].y = 0;

	
		for (int i = 0; i<y_span; i++)
			for (int o = 0; o<x_row; o++)
			{
				char s;
				cin >> s;
				map[o][i] = s;
				judge[o][i] = false;
				if (s == 'r')
				{
					people_x = o;
					people_y = i;
					judge[o][i] = true;
				}
				else if (s == 'a')
				{
					answer_x = o;
					answer_y = i;
				}
			}
		GoNode first(people_x, people_y, judge);
		father.push(first);

		while (!father.empty())
		{
			if (father.front().MyNextNode(walk, son, judge, map))
			{
				cout << sum << endl;
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
			if (father.empty() && son.empty()&& wenyishou.empty())
			{
				cout << "Poor ANGEL has to stay in the prison all his life."<<endl;
				break;
			}
		}
	}

}