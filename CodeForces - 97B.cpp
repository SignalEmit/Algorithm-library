#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node 
{
	int x;
	int y;
};
vector<Node> NodeLocation;
vector<Node> choose;
bool cmd(Node &x, Node &y)
{
	return x.x < y.x;
}
void DFS(int star_, int end_)
{
	int between = (star_ + end_) / 2;
	for(int i=star_;i<=end_;i++)
		if (NodeLocation[i].x != NodeLocation[between].x)
		{
			Node s;
			s.x = NodeLocation[between].x;
			s.y = NodeLocation[i].y;
			choose.push_back(s);
		}
	if (star_ + 1 == end_)
		return;
	DFS(star_, (star_ + end_) / 2);
	DFS((star_ + end_) / 2, end_);
}
void print()
{
	int choose_size = choose.size();
	if (!choose.empty())
	{
		Node s;
		s.x = choose[0].x;
		s.y = choose[0].y;
		choose.push_back(s);
		for (int o = 0; o < choose_size; o++)
		{
			for (int i = choose_size - 1; i < choose.size(); i++)
			{
				if (choose[o].x != choose[i].x && choose[o].y != choose[i].y && (i == choose.size() - 1))
				{
					choose.push_back(choose[i]);
				}
				else if (choose[o].x == choose[i].x && choose[o].y == choose[i].y)
					continue;
			}
		}
	}
	choose.erase(choose.begin(), choose.begin() + choose_size);
	cout << NodeLocation.size() + choose.size() << endl;
	for (int i = 0; i < NodeLocation.size(); i++)
	{
		cout << NodeLocation[i].x << " " << NodeLocation[i].y << endl;
	}
	for (int i = 0; i < choose.size(); i++)
	{
		cout << choose[i].x << " " << choose[i].y << endl;
	}
}
int main()
{
	int N;
	cin >> N;
	Node s;
	choose.clear();
	NodeLocation.clear();
	sort(NodeLocation.begin(), NodeLocation.end(), cmd);
	for (int i = 0; i < N; i++)
	{
		cin >> s.x >> s.y;
		NodeLocation.push_back(s);
	}
	DFS(0, NodeLocation.size() - 1);
	print();
	system("pause");
	return 0;
}