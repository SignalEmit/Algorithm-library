#include<iostream>
#include<vector>
using namespace std;
class Node
{
private:
	bool state;						//true为开  false为关
	int Number;						//编号
public:
	Node(int Number_)							//初始化
	{
		state = false;
		Number = Number_+1;
	}
	void Change()
	{
		state = !state;
	}
	bool Back_State()
	{
		return state;
	}
	int Back_Number()
	{
		return Number;
	}
};
int main()
{
	vector<Node> NodeVector;
	long D, I;
	long show = 0;
	while (1)
	{
		NodeVector.clear();
		cout << "请输入树的深度：";
		cin >> D;
		cout << "请输入小球个数：";
		cin >> I;
		int Deep = (1 << D) - 1;
		for (int i = 0; i < Deep; i++)
		{
			Node newNode(i);
			NodeVector.push_back(newNode);
		}

		for (int i = 0; i < I; i++)
		{

			long jilu = 0;
			for (int s = 0; s < D - 1; s++)									//走完所有深度
			{
				if (!NodeVector[2 * jilu + 1].Back_State())					//此状态 为关闭时
				{
					NodeVector[2 * jilu + 1].Change();
					jilu = 2 * jilu + 1;
					show = jilu;
				}
				else
				{
					NodeVector[2 * (jilu + 1)].Change();
					jilu = 2 * (jilu + 1);
					show = jilu;
				}
			}
			
		}
		cout <<"最后的数字"<< show + 1<<endl;
	}
	system("pause");
}