#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<climits>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

const int NV = 102;
const int NE = 20002;
int n, m;

int yesterday[20];
int today[20];
int Need[20];

struct Sum
{
	int MinMoneyNumber;
	double Money;
};
bool papap(const Sum & a, const Sum & b)
{
	return a.Money > b.Money;
}

struct carTranlation
{
	int NeedCar;
	int TranlationCar;
	double Money;

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
bool judge_return()						//false不用跳出  true要跳出
{
	for (int l = 0; l < 20; l++)						//遍历20个元素当都大于等于0时跳出循环
		if (Need[l] < 0)								//当小于0时匹配操作
			return false;
		else if (l == 19)
			return true;
}
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
double sum = 0;
vector<carTranlation> MinMoney;
double Vehicles[20];						//亏损钱数
double zhuanqian[20];
void GOGOGO(int i)
{
	if (Need[MinMoney[i].NeedCar] <= 0 || Need[MinMoney[i].TranlationCar] >= 0)
		return;
	if (abs(Need[MinMoney[i].NeedCar]) >= abs(Need[MinMoney[i].TranlationCar]))
	{
		yesterday[MinMoney[i].NeedCar] += abs(Need[MinMoney[i].TranlationCar]);
		yesterday[MinMoney[i].TranlationCar] -= abs(Need[MinMoney[i].TranlationCar]);

		cout << print(MinMoney[i].TranlationCar) << "点向" << print(MinMoney[i].NeedCar) << "点转移" << abs(Need[MinMoney[i].TranlationCar]) << "辆,";

		sum += abs(Need[MinMoney[i].TranlationCar]) * MinMoney[i].Money;
		Need[MinMoney[i].NeedCar] -= abs(Need[MinMoney[i].TranlationCar]);
		Need[MinMoney[i].TranlationCar] = 0;
	}
	else
	{
		yesterday[MinMoney[i].NeedCar] += Need[MinMoney[i].NeedCar];
		yesterday[MinMoney[i].TranlationCar] -= abs(Need[MinMoney[i].NeedCar]);

		cout << print(MinMoney[i].TranlationCar) << "点向" << print(MinMoney[i].NeedCar) << "点转移" << abs(abs(Need[MinMoney[i].NeedCar])) << "辆,";

		sum += abs(Need[MinMoney[i].NeedCar]) * MinMoney[i].Money;
		Need[MinMoney[i].TranlationCar] += abs(Need[MinMoney[i].NeedCar]);			//正的加负的 
		Need[MinMoney[i].NeedCar] = 0;
	}
}

int main()
{
	double Money=0;
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
		cin >> Vehicles[i];
	for (int i = 0; i < 20; i++)
		cin >> zhuanqian[i];


	for (int i = 0; i < 20; i++)
		cin >> yesterday[i];


	for (int countNumber = 0; countNumber < 28; countNumber++)
	{
		cout << "第" << countNumber + 2 << "天：" << endl;
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
					MinMoney.push_back(newCar);
				}
			}
		}
		
		vector<Sum> llll;
		llll.clear();
		for (int i = 0; i < MinMoney.size(); i++)
		{
			Sum a;
			a.MinMoneyNumber = i;
			a.Money = zhuanqian[MinMoney[i].NeedCar]-MinMoney[i].Money - Vehicles[MinMoney[i].NeedCar];
			llll.push_back(a);
		}

		sort(llll.begin(), llll.end(), papap);


		for (int i = 0; i < llll.size(); i++)
		{
				GOGOGO(llll[i].MinMoneyNumber);
		}

		int caryuqi[20];
		int car[20];
		for (int i = 0; i < 20; i++)
		{
			caryuqi[i] = today[i];
			today[i] = yesterday[i];
			car[i] = caryuqi[i] - today[i];
		}
		for (int i = 0; i < 20; i++)
			Money += today[i] * zhuanqian[i];

		for (int i = 0; i < 20; i++)
			cout << today[i]<<" ";

		double ooo = 0;
		
		for (int i = 0; i < 20; i++)
			if (car[i]>0)
				ooo += abs(car[i])*Vehicles[i];
		sum += ooo;
		cout << sum << endl;
	}

	cout << Money-sum;
	system("pause");
	return 0;
}