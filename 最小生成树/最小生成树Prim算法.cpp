#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find(int x,int *node)                                                                                                         //查找根节点
{
	int r = x;
	while (node[r] != -1)                                                                                              //返回根节点 r
		r = node[r];
	
	int i = x, j;
	while (i != r)                                                                                                        //路径压缩
	{
		j = node[i]; // 在改变上级之前用临时变量  j 记录下他的值 
		node[i] = r; 
		i = j;
	}
	return r;
}
bool join(int x, int y,int *node)                                                                                                    //判断x y是否连通，																													   //如果已经连通，就不用管了 //如果不连通，就把它们所在的连通分支合并起,
{
	int fx = find(x, node), fy = find(y, node);
	if (fx != fy)
	{
		node[fx] = fy;
		return true;
	}
	else
		return false;
}
struct side					//一条边为一个对象
{
	int sideStar, sideEnd, sideWeight;			//两点加一条边
};
bool cmd(const side &a, const side &b)
{
	return a.sideWeight < b.sideWeight;
}
side calculateMin(const side &a, const side &b)
{
	return a.sideWeight > b.sideWeight ? a : b;
}
void GOGOGO(const int &roadNumber, const int &villageNumber)
{
	int *Node = new int[villageNumber];
	memset(Node, -1, sizeof(int)*villageNumber);
	vector<int> sumWeight;
	sumWeight.clear();
	side *ManySide;
	ManySide = new side[roadNumber];
	int sideStar, sideEnd, sideWeight;
	for (int i = 0; i < roadNumber; i++)
	{
		cin >> sideStar >> sideEnd >> sideWeight;
		join(sideStar - 1, sideEnd - 1, Node);
		ManySide[i].sideStar = sideStar;
		ManySide[i].sideEnd = sideEnd;
		ManySide[i].sideWeight = sideWeight;

		for (int i = 0; i < roadNumber; i++)
			cout << Node[i] << " ";
		cout << endl;
	}
	sort(ManySide, ManySide + roadNumber, cmd);				//排序
	memset(Node, -1, sizeof(int)*villageNumber);

	sumWeight.push_back(ManySide[0].sideWeight);
	join(ManySide[0].sideStar - 1, ManySide[0].sideEnd - 1, Node);				//第一次加入肯定行

	int o = 1;
	for (int i = 1; i < villageNumber - 1; i++)			//如果能生成最小生成树 则需要点之和-1条边
	{
		for (; o < roadNumber; o++)
			if (join(ManySide[o].sideStar - 1, ManySide[o].sideEnd - 1, Node))
			{
				sumWeight.push_back(ManySide[o].sideWeight);
				break;
			}
	}

	for (int i = 0; i < villageNumber; i++)
		cout << Node[i] << " ";
	vector<int> judge;
	judge.clear();
	for (int i = 0; i < villageNumber; i++)
		if (Node[i] == -1)
			judge.push_back(i);
	int sum = 0;
	if (judge.size() == 1)
	{
		for (int i = 0; i < sumWeight.size(); i++)
			sum += sumWeight[i];
	}
	else
	{
		for (int i = 1; i < judge.size(); i++)
		{
			join(judge[0], judge[1], Node);
			for (int o = 0; o < roadNumber; o++)
				if (ManySide[judge[0]].sideStar == ManySide[o].sideStar && ManySide[judge[0]].sideEnd == ManySide[o].sideEnd)
					sumWeight.push_back(ManySide[o].sideWeight);
		}

		for (int i = 0; i < sumWeight.size(); i++)
			sum += sumWeight[i];
	}
	cout << sum << endl;
}
int main()
{
	int roadNumber, villageNumber;
	

	while (cin >> roadNumber >> villageNumber)
	{
		if (roadNumber == 0)
			break;
		GOGOGO(roadNumber, villageNumber);
	}
	system("pause");
}