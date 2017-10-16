#include<iostream>
#include<vector>
	using namespace std;
	   const int MAX = 1000 + 10;
	   int village[MAX];

	   int find(int x)                                                                                                         //查找根节点
	   {
		   int r = x;
		   while (village[r] != -1)                                                                                              //返回根节点 r
			   r = village[r];

		   int i = x, j;
		   while (i != r)                                                                                                        //路径压缩
		   {
			   j = village[i]; // 在改变上级之前用临时变量  j 记录下他的值 
			   village[i] = r; //把上级改为根节点
			   i = j;
		   }
		   return r;
	   }
	   void join(int x, int y)                                                                                                    //判断x y是否连通，
																																  //如果已经连通，就不用管了 //如果不连通，就把它们所在的连通分支合并起,
	   {
		   int fx = find(x), fy = find(y);
		   if (fx != fy)
			   village[fx] = fy;
	   }
	   int main()
	   {
		   int N, M;
		   while (cin >> N)
		   {
			   if (N == 0)
				   break;
			   cin >> M;
			   if (M == 0)
			   {
				   cout << N - 1 << endl;
				   continue;
			   }
			   for (int i = 1; i <= N; i++)
				   village[i] = -1;

			   for (int i = 1; i <= M; i++)
			   {
				   int a, b;
				   cin >> a >> b;
				   if (village[a] == -1 && village[b] == -1)
					   village[b] = a;
				   else if (village[a] != -1 && village[b] == -1)
					   village[b] = a;
				   else if (village[a] == -1 && village[b] != -1)
					   village[a] = b;
				   else
				   {
					   join(a,b);
				   }
			   }
			   int sum = 0;
			   for (int i = 1; i <= N; i++)
				   if (village[i] == -1)
					   sum++;
			   cout << sum - 1 << endl;

		   }

	   }

