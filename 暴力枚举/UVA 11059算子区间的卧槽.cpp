/*

�Բ� �ӵ������
���⣺
����n��Ԫ����ɵ�����S���ҳ�һ���˻��������������С����������ĳ˻��������������0(��ʾ�޽�)��1<=n<=18��-10<=Si<=10��ÿһ������֮���ÿհ��зָ����������Ҫ�����"Case #M: The maximum product is P.",����MΪ�����ţ�PΪ�˻�ֵ��
������
Sample Input
3
2 4 -3

5
2 5 -1 2 -1
Sample Output
Case #1: The maximum product is 8.

Case #2: The maximum product is 20.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Number[18];
struct IS_ONE
{
	bool is_one;
	int answer;
};
int main()
{
	int cinCount;
	vector<int> TheAnswer;
	int fff = 0;
	while (cin>>cinCount)
	{
		if (cinCount <= 0)
			break;
		fff++;
		TheAnswer.clear();
		for (int i = 0; i < cinCount; i++)
			cin >> Number[i];
		int sum=1;
		
		bool is_one = false;
		for (int i = 0; i < cinCount; i++)
			if (Number[i] > 0)
			{
				if (Number[i] == 1)
					is_one = true;
				sum *= Number[i];
				if (i == cinCount - 1)
				{
					if(sum!=1)
						TheAnswer.push_back(sum);
					else
						if(is_one)
							TheAnswer.push_back(sum);
					is_one = false;
					sum = 1;
				}
			}
			else
			{
				if (sum != 1)
					TheAnswer.push_back(sum);
				else
					if (is_one)
						TheAnswer.push_back(sum);
				is_one = false;
				sum = 1;
			}
		if (!TheAnswer.empty())
		{
			sort(TheAnswer.begin(), TheAnswer.end());
			if (TheAnswer[TheAnswer.size() - 1] > 0)
				printf("Case #%d: The maximum product is %d.\n",fff, TheAnswer[TheAnswer.size() - 1]);
			else
				cout << "0"<<endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
}