#include<iostream>
using namespace std;
int find(int x, int *node)                                                                                                         //���Ҹ��ڵ�
{
	int r = x;
	while (node[r] != -1)                                                                                              //���ظ��ڵ� r
		r = node[r];

	int i = x, j;
	while (i != r)                                                                                                        //·��ѹ��
	{
		j = node[i]; // �ڸı��ϼ�֮ǰ����ʱ����  j ��¼������ֵ 
		node[i] = r; //���ϼ���Ϊ���ڵ�
		i = j;
	}
	return r;
}
void join(int x, int y, int *node)                                                                                                    //�ж�x y�Ƿ���ͨ��
																																	  //����Ѿ���ͨ���Ͳ��ù��� //�������ͨ���Ͱ��������ڵ���ͨ��֧�ϲ���,
{
	int fx = find(x, node), fy = find(y, node);
	if (fx != fy)
		node[fx] = fy;
}
struct Node
{
	int NodeNumber;

};
int main()
{
	int roadNumber, villageNumber;
	side *ManySide;

	while (cin >> roadNumber >> villageNumber)
	{
		ManySide = new side[roadNumber];
		int sideStar, sideEnd, sideWeight;
		for (int i = 0; i < roadNumber; i++)
		{
			cin >> sideStar >> sideEnd >> sideWeight;
			ManySide[i].sideStar = sideStar;
			ManySide[i].sideEnd = sideEnd;
			ManySide[i].sideWeight = sideWeight;
		}
		sort(ManySide, ManySide + roadNumber, cmd);

		for (int i = 0; i < roadNumber; i++)								//װ��
		{
			ManySide[i].index = i;
			int nowSideStar = ManySide[i].sideStar;
			int nowSideEnd = ManySide[i].sideEnd;
			for (int o = 0; o < roadNumber; o++)
				if (i != o && nowSideStar == ManySide[o].sideStar || nowSideEnd == ManySide[o].sideEnd)
				{
					ManySide[i].pushSide(ManySide[o]);
				}
		}

		bool *Judge = new bool[roadNumber];
		memset(Judge, false, sizeof(bool)*roadNumber);
		sumweight.push_back(ManySide[0].sideWeight);
		overPushSide.push_back(ManySide[0]);
		Judge[0] = true;
		for (int i = 1; i < villageNumber - 1; i++)			//�����������С������ ����Ҫ��֮��-1����
		{
			side min_Index = overPushSide[0].OverTheEdge[0];
			for (int o = 0; o<overPushSide.size(); o++)
				if (!Judge[overPushSide[o].index])
					min_Index = min(min_Index, overPushSide[o].OverTheEdge[0], calculateMin);			//�ҳ���С��


			for (int o = 0; o<overPushSide.size(); o++)
				if (min_Index.sideStar == overPushSide[o].OverTheEdge[0].sideStar && min_Index.sideEnd == overPushSide[o].OverTheEdge[0].sideEnd)
				{
					overPushSide[o].removeHeadSide();
					break;
				}

			side newSide = ManySide[min_Index.index];
			newSide.removeHeadSide();
			overPushSide.push_back(min_Index);
		}

	}
}