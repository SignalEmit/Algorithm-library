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

					if (x_+1<3 && x_ + 1 == setNode[o].x && y_ == setNode[o].y)			//û��
					{
						headlist[i].push_back(setNode[o]);
						continue;
					}

					if (y_-1>=0 && x_ == setNode[o].x && y_-1 == setNode[o].y)	//û��
					{
						headlist[i].push_back(setNode[o]);
						continue;
					}

					if (y_ + 1<3 && x_ == setNode[o].x && y_+1 == setNode[o].y)	//û��
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
		int count = 0;						//������λ��where ��Ӧ�ü���where  ���жϴ� ����һƬ???����
		setNode.clear();
		for (auto i = headlist[star - 1].begin(); i != headlist[star - 1].end(); i++)				//��һ�θ��¶��к�����
		{
			CharQueue.push(*i);
			setNode.push_back(*i);
		}

		
		while (!CharQueue.empty())
		{
			CharQueue.pop();					//������
			if (CharQueue.empty())				//��ֹ�±ߵ�  CharQueue.front()�Ϳ� ����˲�䱬ը
				break;

			for (auto i = headlist[CharQueue.front().number].begin(); i != headlist[CharQueue.front().number].end(); i++)			//�������
			{
				if (i != headlist[CharQueue.front().number].begin())									//�������ڽӱ�ĵ�һ��  ӦΪ�ڽӱ�ĵ�һ���������� ��Ȼ�ֵ�+1
				{
					for (int o = 0; o < setNode.size(); o++)											//�������
					{
						if (i->x== setNode[o].x && i->y==setNode[o].y)
						{
							break;							//�������ȵ�ֱ������ѭ��   ��Ҫ�����ڲ���ȥ
						}
						if (o == setNode.size() - 1)					//������������һ����û������
						{
							CharQueue.push(*i);						//�����
							setNode.push_back(*i);				//������
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
