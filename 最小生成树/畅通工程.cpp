#include<iostream>
#include<vector>
	using namespace std;
	   const int MAX = 1000 + 10;
	   int village[MAX];

	   int find(int x)                                                                                                         //���Ҹ��ڵ�
	   {
		   int r = x;
		   while (village[r] != -1)                                                                                              //���ظ��ڵ� r
			   r = village[r];

		   int i = x, j;
		   while (i != r)                                                                                                        //·��ѹ��
		   {
			   j = village[i]; // �ڸı��ϼ�֮ǰ����ʱ����  j ��¼������ֵ 
			   village[i] = r; //���ϼ���Ϊ���ڵ�
			   i = j;
		   }
		   return r;
	   }
	   void join(int x, int y)                                                                                                    //�ж�x y�Ƿ���ͨ��
																																  //����Ѿ���ͨ���Ͳ��ù��� //�������ͨ���Ͱ��������ڵ���ͨ��֧�ϲ���,
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

