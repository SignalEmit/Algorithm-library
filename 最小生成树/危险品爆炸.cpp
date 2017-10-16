#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 1e5+10;
int find(int x,int *Node)                                                                                                         //查找根节点
{
	int r = x;
	while (Node[r] != -1)                                                                                              //返回根节点 r
		r = Node[r];

	return r;
}
void join(int x, int y, int *Node)                                                                                                    //判断x y是否连通，
																														   //如果已经连通，就不用管了 //如果不连通，就把它们所在的连通分支合并起,
{
	int fx = find(x, Node), fy = find(y, Node);
	if (fx != fy)
		Node[fx] = fy;
}
int main()
{
	int *bang;
	int a, b;
	
	while (cin >> a	&& a!=-1)
	{
		int sum = 0;
		bang = new int[MAX];
		memset(bang, -1, sizeof(int)*MAX);
		while (a != -1)
		{
			cin >> b;
			if (find(a , bang) == find(b, bang))
			{
				sum++;
			}
			else
			{
				join(a , b , bang);
			}
			cin >> a;
		}
		cout << sum << endl;
	}
}