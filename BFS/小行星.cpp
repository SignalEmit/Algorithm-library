#include<iostream>
#include<queue>
#include<string>
using namespace std;
int N;
int answer_x;
int answer_y;
int answer_z;

struct GoNode
{
	int x;
	int y;
	int z;
	GoNode() {}
	GoNode(int x_, int y_,int z_,bool ***JudgeNode) :x(x_), y(y_),z(z_)
	{
		JudgeNode[x][y][z] = true;				//这个节点
	}
	bool MyNextNode(const GoNode *walk, queue<GoNode> &Nodepush, bool ***JudgeNode,char ***Map)
	{
		for (int i = 0; i < 6; i++)
			if ( x + walk[i].x >= 0 && x + walk[i].x <= N-1  && y + walk[i].y >= 0 && y + walk[i].y <= N-1 && z + walk[i].z >= 0 && z + walk[i].z <= N - 1 && Map[x + walk[i].x][y + walk[i].y][z + walk[i].z] != 'X')
			{
				if (answer_x == x + walk[i].x && answer_y == y + walk[i].y && answer_z == z + walk[i].z)
				{
					return true;
				}
				if (!JudgeNode[x + walk[i].x][y + walk[i].y][z + walk[i].z])
				{
					GoNode s(x + walk[i].x, y + walk[i].y, z + walk[i].z, JudgeNode);
					Nodepush.push(s);										//压入链表
				}
			}
		return false;
	}
};
int main()
{
	queue<GoNode> father;
	queue<GoNode> son;
	string a;
	while (cin>>a>>N)
	{
		while (!father.empty())
			father.pop();
		while (!son.empty())
			son.pop();
		char ***Map;
		bool ***Judge;
		Map = new char **[N];
		Judge = new bool **[N];
		for (int i = 0; i < N; i++)
		{
			Map[i] = new char *[N];
			Judge[i] = new bool *[N];
			for (int o = 0; o < N; o++)
			{
				Map[i][o] = new char[N];
				Judge[i][o] = new bool[N];
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
				{
					cin >> Map[k][j][i];
					Judge[k][j][i] = false;
				}
		GoNode walk[6];
		walk[0].x = 1; walk[0].y = 0; walk[0].z = 0;
		walk[1].x = -1; walk[1].y = 0; walk[1].z = 0;
		walk[2].x = 0; walk[2].y = 1; walk[2].z = 0;
		walk[3].x = 0; walk[3].y = -1; walk[3].z = 0;
		walk[4].x = 0; walk[4].y = 0; walk[4].z = 1;
		walk[5].x = 0; walk[5].y = 0; walk[5].z = -1;

		int x, y, z;
		cin >> x >> y >> z;
		cin >> answer_x >> answer_y >> answer_z;
		string p;
		cin >> p;

		if (x == answer_x && y == answer_y && z==answer_z)
		{
			cout << N<<" "<<0<< endl;
			continue;
		}

		GoNode s(x, y, z, Judge);
		father.push(s);

		int sum = 1;
		while (!father.empty())
		{
			if (father.front().MyNextNode(walk,son,Judge,Map))
			{
				cout << N<<" " <<sum<< endl;
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

			if (father.empty() && son.empty())
			{
				cout << "NO ROUTE" << endl;
				break;
			}
		}
	}
}