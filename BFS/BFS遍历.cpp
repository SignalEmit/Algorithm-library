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
		cout << "������ͼ�Ľ�㣺";
		cin >> str;

		ItemList = new list<Node>[str.size()];
		for (int i = 0; i < str.size(); i++)
		{

			Node s(str.at(i), i);
			ItemList[i].push_back(s);
		}

		int x, y;
		cout << "������������֮��Ĺ�ϵ��";
		while (cin >> x >> y)
		{
			Node s(str.at(y - 1), y - 1);
			ItemList[x-1].push_back(s);
		}
	}
	void BFS(int star)
	{


		for (auto i = ItemList[star - 1].begin(); i != ItemList[star - 1].end(); i++)				//��һ�θ��¶��к�����
		{
			CharQueue.push(*i);
			CharVector.push_back(*i);
		}
		

		while (!CharQueue.empty())
		{
			CharQueue.pop();					//������
			if (CharQueue.empty())				//��ֹ�±ߵ�  CharQueue.front()�Ϳ� ����˲�䱬ը
				break;

			for (auto i = ItemList[CharQueue.front().number].begin(); i != ItemList[CharQueue.front().number].end(); i++)			//�������
			{
				if (i != ItemList[CharQueue.front().number].begin())									//�������ڽӱ�ĵ�һ��  ӦΪ�ڽӱ�ĵ�һ���������� ��Ȼ�ֵ�+1
				{
					for (int o = 0; o < CharVector.size(); o++)											//�������
					{
						if (i->data == CharVector[o].data)
						{
							break;							//�������ȵ�ֱ������ѭ��   ��Ҫ�����ڲ���ȥ
						}
						if (o == CharVector.size() - 1)					//������������һ����û������
						{
							CharQueue.push(*i);						//�����
							CharVector.push_back(*i);				//������
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


