#include<iostream>
#include<list>
#include<string>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
	char data;
	int number;
	Node(char data_,int number_):data(data_),number(number_){}
};
class MyGraph
{
private:
	list<Node> *ItemList;
	string str;
	queue<Node> CharQueue;
	vector<Node> CharVector;
public:
	MyGraph()
	{
		cout << "请输入图的结点：";
		cin >> str;

		ItemList = new list<Node>[str.size()];
		for (int i = 0; i < str.size(); i++)
		{

			Node s(str.at(i), i);
			ItemList[i].push_back(s);
		}

		int x, y;
		cout << "请输入各个结点之间的关系：";
		while (cin >> x >> y)
		{
			Node s(str.at(y - 1), y - 1);
			ItemList[x-1].push_back(s);
		}
	}
	void BFS(int star)
	{


		for (auto i = ItemList[star - 1].begin(); i != ItemList[star - 1].end(); i++)				//第一次更新队列和容器
		{
			CharQueue.push(*i);
			CharVector.push_back(*i);
		}
		

		while (!CharQueue.empty())
		{
			CharQueue.pop();					//出队列
			if (CharQueue.empty())				//防止下边的  CharQueue.front()滞空 导致瞬间爆炸
				break;

			for (auto i = ItemList[CharQueue.front().number].begin(); i != ItemList[CharQueue.front().number].end(); i++)			//链表遍历
			{
				if (i != ItemList[CharQueue.front().number].begin())									//不能是邻接表的第一个  应为邻接表的第一个是他自身 不然又得+1
				{
					for (int o = 0; o < CharVector.size(); o++)											//数组遍历
					{
						if (i->data == CharVector[o].data)
						{
							break;							//如果有相等的直接跳出循环   不要让他在查下去
						}
						if (o == CharVector.size() - 1)					//如果检索到最后一个还没检索到
						{
							CharQueue.push(*i);						//入队列
							CharVector.push_back(*i);				//入容器
						}
					}
				}
			}
		}
		for (int i = 0; i < CharVector.size(); i++)
			cout << CharVector[i].data << "  ";
		
	}
	void show()
	{
		for (int i = 0; i < str.size(); i++)
		{
			cout << ItemList[i].begin()->data << " ";
			for (auto o = ItemList[i].begin(); o != ItemList[i].end(); o++)
				if (o != ItemList[i].begin())
					cout << " " << o->data;
			cout << endl;
		}

	}
};
int main()
{
	MyGraph s;
	//s.show();
	s.BFS(1);
	system("pause");
}


