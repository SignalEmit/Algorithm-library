#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;
struct Node
{
	int x;
	int y;
	int number;
	Node(int x_, int y_,int number_) :x(x_), y(y_),number(number_) {}
};
class MyBFS
{
private:
	list<Node> *headlist;
	vector<Node> setNode;
	queue<Node> CharQueue;
public:
	MyBFS()
	{
		char a[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int o = 0; o < 3; o++)
			{
				cin >> a[o][i];
				cout << o << " " << i;
				if (a[o][i] == '#')
				{
					Node s(o, i, setNode.size());
					setNode.push_back(s);
				}
				cout << endl;
			}
			}
		headlist = new list<Node>[setNode.size()];

		for (int i = 0; i < setNode.size(); i++)
		{
			headlist[i].push_back(setNode[i]);
			cout << "headlist:x:" << headlist[i].begin()->x << "  y:" << headlist[i].begin()->y<<"  Node:x:"<< setNode[i].x << "  y:" << setNode[i].y<<endl;
		}

		for (int i = 0; i < setNode.size(); i++)
		{
			int x_ = headlist[i].begin()->x;
			int y_ = headlist[i].begin()->y;


			for (int o = 0; o < setNode.size(); o++)
			{
				if (!(x_ == setNode[o].x && y_ == setNode[o].y))
				{
					if (x_-1>=0 && x_ - 1 == setNode[o].x && y_ == setNode[o].y )
					{
						headlist[i].push_back(setNode[o]);
						continue;
					}

					if (x_+1<3 && x_ + 1 == setNode[o].x && y_ == setNode[o].y)			//没改
					{
						headlist[i].push_back(setNode[o]);
						continue;
					}

					if (y_-1>=0 && x_ == setNode[o].x && y_-1 == setNode[o].y)	//没改
					{
						headlist[i].push_back(setNode[o]);
						continue;
					}

					if (y_ + 1<3 && x_ == setNode[o].x && y_+1 == setNode[o].y)	//没改
					{
						headlist[i].push_back(setNode[o]);
						continue;
					}
				}
			}
		
		}
		
		
	}


	int BFS(int star)
	{
		int count = 0;						//计数器位置where 你应该加在where  ？判断处 走完一片???难受
		setNode.clear();
		for (auto i = headlist[star - 1].begin(); i != headlist[star - 1].end(); i++)				//第一次更新队列和容器
		{
			CharQueue.push(*i);
			setNode.push_back(*i);
		}

		
		while (!CharQueue.empty())
		{
			CharQueue.pop();					//出队列
			if (CharQueue.empty())				//防止下边的  CharQueue.front()滞空 导致瞬间爆炸
				break;

			for (auto i = headlist[CharQueue.front().number].begin(); i != headlist[CharQueue.front().number].end(); i++)			//链表遍历
			{
				if (i != headlist[CharQueue.front().number].begin())									//不能是邻接表的第一个  应为邻接表的第一个是他自身 不然又得+1
				{
					for (int o = 0; o < setNode.size(); o++)											//数组遍历
					{
						if (i->x== setNode[o].x && i->y==setNode[o].y)
						{
							break;							//如果有相等的直接跳出循环   不要让他在查下去
						}
						if (o == setNode.size() - 1)					//如果检索到最后一个还没检索到
						{
							CharQueue.push(*i);						//入队列
							setNode.push_back(*i);				//入容器
						}
					}
				}
			}
		}

	}
};
int main()
{
	MyBFS s;
	system("pause");
}
