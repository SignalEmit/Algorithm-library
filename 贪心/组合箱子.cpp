#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<long> BoxList;
	vector<long> zhi;
	while (1)
	{
		BoxList.clear();
		for (int i = 0; i < 6; i++)
		{
			long number;
			cin >> number;
			BoxList.push_back(number);
		}
		if (BoxList[0] == 0 && BoxList[1] == 0 && BoxList[2] == 0 && BoxList[3] == 0 && BoxList[4] == 0 && BoxList[5] == 0)
			break;


		int sum = 0;

			for (int i = BoxList.size() - 1; i >= 0; i--)
			{
				switch (i)
				{
				case 0:
				{
					sum += BoxList[0] / 36;				//3大于等于4
					BoxList[0] %= 36;					//小于3的
					if (BoxList[0] == 0)
						break;
					else if (BoxList[0] < 36)
						BoxList[0] = 1;


				}; break;
				case 1:
				{
					if (BoxList[1] != 0)
					{
						sum += BoxList[1] / 9;
						BoxList[1] %= 9;
						if (BoxList[1] == 0)
							break;
						int last = 36 - BoxList[1] * 4;
						BoxList[1] = 1;
						if (BoxList[0] > last)
						{
							BoxList[0] -= last;
						}
						else
						{
							BoxList[0] = 0;
						}
					}
				}; break;
				case 2:
				{
					if (BoxList[2] != 0)
					{
						sum += BoxList[2] / 4;					//3大于等于4
						BoxList[2] %= 4;						//小于3的
						if (BoxList[2] == 0)
							break;
						int last = 36 - 9 * BoxList[2];			//需要的个数
						BoxList[2] = 1;
						if (last > BoxList[1] * 4)				//如果需要的大于
						{
							last-=BoxList[1]*4;
							BoxList[1] = 0;
							if (BoxList[0] >= last)
								BoxList[0] -= last;
							else
								BoxList[0] = 0;
						}
						else if (last < BoxList[1] * 4)
						{
							BoxList[1] -= last / 4;					//现在2*2的个数
							if (BoxList[0] >=last%4)
							{
								BoxList[0] -= last % 4;
							}
							else
							{
								BoxList[0] = 0;
							}
						}
					}
				}; break;
				case 3:
				{
					if (BoxList[3] != 0)
					{
						for (int s = 0; s < BoxList[3]; s++)
						{
							if (BoxList[1] >= 5)
							{
								BoxList[1] -= 5;
							}
							else if (BoxList[1] < 5)
							{
								if (BoxList[0] >= 20 - BoxList[1] * 4)
								{
									BoxList[0] -= 20 - BoxList[1] * 4;
									BoxList[1] = 0;
								}
								else
								{
									BoxList[0] = 0;
									BoxList[1] = 0;
								}
							}
							else if (BoxList[0] >= 20)
							{
								BoxList[1] -= 20;
							}
							else if (BoxList[0] < 20)
							{
								BoxList[0] = 0;
								break;
							}
						}
					}
				}; break;
				case 4:
				{
					if (BoxList[4] != 0)
					{
						for (int s = 0; s < BoxList[4]; s++)
							if (BoxList[0] >= 11)
							{
								BoxList[0] -= 11;
							}
							else
							{
								BoxList[0] = 0;
								break;
							}
					}
				}; break;
				break;
				default:
					break;
				}
			}
			for (int pppp = 0; pppp < BoxList.size(); pppp++)
				sum += BoxList[pppp];
			zhi.push_back(sum);
	}
	for (int i = 0; i < zhi.size(); i++)
		cout << zhi[i] << endl;
	return 0;
}