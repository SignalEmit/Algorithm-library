#include<iostream>
using namespace std;
const int Max = 40;
char c[Max][Max];
bool Judge[Max][Max];
int x, y;
void DFS(int x_present, int y_present, int &count)
{
	if (x_present >= 0 && x_present <= x	&&	y_present >= 0 && y_present <= y)
	{
		

		if (c[x_present - 1][y_present] == '.')
		{
			count++;
			c[x_present][y_present] = '#';
		
			DFS(x_present - 1, y_present, count);
		}
		else if(c[x_present - 1][y_present] == '#')
			c[x_present][y_present] = '#';

		if (c[x_present + 1][y_present] == '.')
		{
			count++;
			c[x_present][y_present] = '#';
			
			DFS(x_present + 1, y_present, count);
		}
		else if (c[x_present +1][y_present] == '#')
			c[x_present][y_present] = '#';

		if (c[x_present ][y_present- 1] == '.')
		{
			count++;
			c[x_present][y_present] = '#';
			
			DFS(x_present , y_present- 1, count);
		}
		else if (c[x_present ][y_present-1] == '#')
			c[x_present][y_present] = '#';

		if (c[x_present ][y_present+ 1] == '.')
		{
			count++;
			c[x_present][y_present] = '#';
		
			DFS(x_present , y_present+ 1, count);
		}
		else if (c[x_present ][y_present+1] == '#')
			c[x_present][y_present+1] = '#';
	}
}
int main()
{
	for (; ; )
	{
		int x_, y_;
		cin >> x >> y;
		for (int i = 0; i < y; i++)
			for (int o = 0; o < x; o++)
			{
				cin >> c[o][i];
				if (c[o][i] == '@')
				{
					x_ = o;
					y_ = i;
				}
			}
		int count = 0;
		DFS(x_, y_,count);
		cout << count + 1 << endl;
	}
	return 0;
}