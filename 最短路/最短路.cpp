#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<climits>
#include<queue>
#include<cmath>
using namespace std;

const int NV = 102;
const int NE = 20002;
int n, m;

int yesterday[20];
int today[20];
int Need[20];
struct carTranlation
{
	int NeedCar;
	int TranlationCar;
	double Money;

};
struct cmp 
{
	bool operator() (carTranlation a, carTranlation b)
	{
		return a.Money > b.Money;
	}
};
struct carLocation
{
	int x;
	int y;
	int carcount;
	double HowLong[20];
	double Money[20];
	double endMoney[20];
};
struct Dijkstra
{
	int n, size;
	int  head[NV];
	int mark[NV];
	double dis[NV];

	struct node
	{
		int v;
		double dis;
		node() {}
		node(int V, double DIS) : v(V), dis(DIS) {}
		friend bool operator< (const node a, const node b)
		{
			return a.dis > b.dis;
		}
	};

	struct edge
	{
		int v, next;
		double w;
		edge() {}
		edge(int V, int NEXT, double W = 0) : v(V), next(NEXT), w(W) {}
	}E[NE];

	inline void init(int x)
	{
		n = x, size = 0;
		memset(head, -1, sizeof(int)* (x + 1));
	}

	inline void insert(int u, int v, double w)
	{
		E[size] = edge(v, head[u], w);
		head[u] = size++;
	}

	void print()
	{
		for (int i = 0; i < n; i++) {
			printf("%d：", i);
			for (int j = head[i]; j != -1; j = E[j].next) {
				printf("%d", E[j].v);
			}puts("");
		}
	}

	double dijkstra(int src, int des)
	{
		node first, next;
		priority_queue<node> Q;
		for (int i = 0; i <= n; i++)
		{
			dis[i] = INT_MAX;
			mark[i] = false;
		}

		dis[src] = 0;
		Q.push(node(src, 0));

		while (!Q.empty())
		{
			first = Q.top();
			Q.pop();
			mark[first.v] = true;

			for (int i = head[first.v]; i != -1; i = E[i].next) {
				if (mark[E[i].v])
					continue;
				next = node(E[i].v, double(first.dis) + E[i].w);
				if (next.dis < dis[next.v])
				{
					dis[next.v] = next.dis;
					Q.push(next);
				}
			}
		}
		return dis[des];
	}
}G;
char print(int c)
{
	switch (c)
	{
	case 0:return 'A'; break;
	case 1:return 'B'; break;
	case 2:return 'C'; break;
	case 3:return 'D'; break;
	case 4:return 'E'; break;
	case 5:return 'F'; break;
	case 6:return 'G'; break;
	case 7:return 'H'; break;
	case 8:return 'I'; break;
	case 9:return 'J'; break;
	case 10:return 'K'; break;
	case 11:return 'L'; break;
	case 12:return 'M'; break;
	case 13:return 'N'; break;
	case 14:return 'O'; break;
	case 15:return 'P'; break;
	case 16:return 'Q'; break;
	case 17:return 'R'; break;
	case 18:return 'S'; break;
	case 19:return 'T'; break;
	}
}
int main()
{
	double sum=0;
	priority_queue< carTranlation,vector<carTranlation>, cmp > sss;
	carLocation carNmber[20];
	for (int i = 0; i < 20; i++)
		cin >> carNmber[i].x;

	for (int i = 0; i < 20; i++)
		cin >> carNmber[i].y;
	for (int i = 0; i < 20; i++)
		cin >> carNmber[i].carcount;

	for (int i = 0; i<20; i++)
		for (int o = 0; o < i + 1; o++)
		{
			double s;
			cin >> s;
			carNmber[i].Money[o] = s;
			carNmber[o].Money[i] = s;
		}
	for (int i = 0; i<20; i++)
		for (int o = 0; o < i + 1; o++)
		{
			carNmber[i].HowLong[o] = sqrt(pow(carNmber[o].x - carNmber[i].x, 2) + pow(carNmber[o].y - carNmber[i].y, 2))*1.2;
			carNmber[o].HowLong[i] = carNmber[i].HowLong[o];
			carNmber[i].endMoney[o] = carNmber[i].HowLong[o] * carNmber[i].Money[o];
			carNmber[o].endMoney[i] = carNmber[i].endMoney[o];
		}

	G.init(20);
	for (int i = 0; i < 20; i++)
		for (int o = 0; o < 20; o++)
			if (i != o)
			{
				G.insert(i, o, carNmber[i].endMoney[o]);
			}



	for (int i = 0; i < 20; i++)
		cin >> yesterday[i];

	for (int countNumber = 0; countNumber < 28; countNumber++)
	{
		cout << "第"<< countNumber+1<<"天：" << endl;
		for (int i = 0; i < 20; i++)
			cin >> today[i];

		for (int i = 0; i < 20; i++)
		{
			Need[i] = today[i] - yesterday[i];
		}
		for (int i = 0; i < 20; i++)
		{
			for (int o = 0; o < 20; o++)
			{
				if (Need[i] < 0 && Need[o] > 0 && i != o)
				{
					carTranlation newCar;
					newCar.NeedCar = o;					//计算出来后  应该是 负数转移至帧数相加
					newCar.TranlationCar = i;			//Tranlation  转向 NeedCar
					newCar.Money = G.dijkstra(newCar.NeedCar, newCar.TranlationCar);
					sss.push(newCar);
				}
			}
		}

		for (; !sss.empty(); sss.pop())
		{
			if (Need[sss.top().NeedCar] <= 0 || Need[sss.top().TranlationCar] >= 0)
				continue;
			if (abs(Need[sss.top().NeedCar]) >= abs(Need[sss.top().TranlationCar]))
			{
				yesterday[sss.top().NeedCar] += abs(Need[sss.top().TranlationCar]);
				yesterday[sss.top().TranlationCar] -= abs(Need[sss.top().TranlationCar]);

				cout << print(sss.top().TranlationCar) << "点向" << print(sss.top().NeedCar) << "点转移" << abs(Need[sss.top().TranlationCar]) << "辆   ";

				sum += abs(Need[sss.top().TranlationCar]) * sss.top().Money;
				Need[sss.top().NeedCar] -= abs(Need[sss.top().TranlationCar]);
				Need[sss.top().TranlationCar] = 0;
			}
			else
			{
				yesterday[sss.top().NeedCar] += Need[sss.top().NeedCar];
				yesterday[sss.top().TranlationCar] -= abs(Need[sss.top().NeedCar]);

				cout << print(sss.top().TranlationCar) << "点向" << print(sss.top().NeedCar) << "点转移" << abs(abs(Need[sss.top().NeedCar])) << "辆   ";

				sum += abs(Need[sss.top().NeedCar]) * sss.top().Money;
				Need[sss.top().TranlationCar] += abs(Need[sss.top().NeedCar]);			//正的加负的 
				Need[sss.top().NeedCar] = 0;
			}

		}

		for (int i = 0; i < 20; i++)
			today[i] = yesterday[i];

		cout << endl;
	}
	cout << sum;
	system("pause");
	return 0;
}
