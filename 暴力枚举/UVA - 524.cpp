/*
计算1-n如何排列成环状才能让俩个数互相为素数
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int prime[] = { 2,3,5,7,11,13,17,19,23,29,31 };		//11个数
bool Judge[20];
vector<int> papap;
void GoAndCout(int N,int bidui)
{
	for (int i = 2; i <= N; i++)
	{
		for(int o=0;o<11;o++)
			if (!Judge[i] && bidui != i && i + bidui == prime[o] )
			{
				Judge[i] = true;
				papap.push_back(i);
				bool is_print = true;			//是否输出,当有false状态时表示 没有全部走过补输出
				for (int f = 1; f <= N; f++)
					if (!Judge[f])
					{
						is_print = false;
					}
				if (is_print)
				{
					bool is_gogogo = true;						
					for(int u=0;u<11;u++)
						if (1 + papap[papap.size() - 1] == prime[u])
						{
							is_gogogo = false;
							break;
						}
					if (!is_gogogo)
					{
						for (int asd = 0; asd < papap.size()-1; asd++)
							cout << papap[asd] <<" ";

						cout<< papap[papap.size() - 1] << endl;
					}
				} 
				else
					GoAndCout(N, i);
				Judge[papap[papap.size()-1]] = false;
				papap.erase(papap.end() - 1);
			}
	}
}
int main()
{
	int N,number=0;
	while (cin >> N)
	{
		if (number++)
			printf("\n");
		printf("Case %d:\n", number);
		papap.clear();
		for (int i = 0; i < 20; i++)
			Judge[i] = false;
		Judge[1] = true;
		papap.push_back(1);
		GoAndCout(N,1);
	}
	return 0;
}