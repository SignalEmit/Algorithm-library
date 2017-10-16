#include<iostream>
#include<vector>
using namespace std;
struct cake
{
	int width;
	int height;
	cake(int width_, int height_) :width(width_), height(height_) {}
};
int main()
{
	int size,*a;
	vector<cake> bigcake;
	cin >> size;
	a = new int[size];
	for (int i = 0; i < size; i++)
	{
		int width, height;
		cin >> width >> height;
		cake l(width, height);
		bigcake.push_back(l);
	}

	for (int i = 0; i < size; i++)
	{
		int width, height, sum = 0;
		width = bigcake[i].width;
		height = bigcake[i].height;
		for (;;)
		{
			if (width > height)
			{
				sum += width / height;
				width = width%height;
			}
			else if (width<height)
			{
				sum += height / width;
				height = height%width;
			}
			else
			{
				a[i]=sum+1;
				
				break;
			}
			if (width == 0 || height == 0)
			{
				a[i]= sum;
				break;
			}
		}
	}
	for (int i = 0; i < size; i++)
		cout << a[i] << endl;
	
}