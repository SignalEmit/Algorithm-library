/*������Ŀ���⣺����һ��������N��Ҫ���С������������abcde / fghij = n�ı��ʽ��
Ҫ��a~fΪ����0~9���Ҳ����ظ�(ǰ�߿���0)��
˼·�������a b c d e f g h i jȫ�������Ļ������Ӷ���10!��û�б�Ҫ��ֱ��ö��
f g h i j��Ȼ�����a b c d e��ȥ�ж��Ƿ�����ظ����ּ��ɡ�
���������
Sample Input 
61
62
0
Sample Output 
There are no solutions for 61.
79546 / 01283 = 62
94736 / 01528 = 62		
*/
#include<iostream>
#include <sstream>
#include<vector>
#include <string>
using namespace std;
bool is_repeat(int number1, int number2)
{
	stringstream ss1, ss2;
	string str, str1, str2;
	ss1 << number1;
	ss1 >> str1;
	ss2 << number2;
	ss2 >> str2;
	str = str1 + str2;
	if (str.size() < 9)
		return false;
	if (str.size() == 9)				//��4����ʱ��Ӹ�0
		str = "0" + str;
	for (int i = 0; i < 9; i++)
		for (int o = i + 1; o < 10; o++)
			if (str[i] == str[o])
				return false;
	return true;
}
struct theSHizi
{
	int chushu;
	int beichushu;
};
string trandlastion(int a)
{
	if (a< 10000)
	{
		stringstream stream;
		stream << a;
		return "0" + stream.str();   //�˴�Ҳ������ stream>>string_temp
	}
	else
	{
		stringstream stream;
		stream << a;
		return stream.str();   //�˴�Ҳ������ stream>>string_temp
	}
}
int main()
{
	int cinNumber;
	vector<theSHizi> outNumber;
	bool ok = false;
	while (cin >> cinNumber)
	{
		if (cinNumber == 0)
			break;
		else
		{
			if (ok)
			{
				cout << endl;
			}
			ok = true;
		}

		outNumber.clear();
		for (int i = 1234; i <= 98765; i++)
		{
			long theNumber = i*cinNumber;
			if (theNumber <= 98765 && is_repeat(theNumber, i))
			{
				theSHizi asd;
				asd.chushu = theNumber;
				asd.beichushu = i;
				outNumber.push_back(asd);
			}
		}
		if (outNumber.size() == 0)
		{
			cout << "There are no solutions for " << cinNumber << "." << endl;
		}
		else
		{
			for (int i = 0; i < outNumber.size(); i++)
			{
				cout << trandlastion(outNumber[i].chushu) << " / " << trandlastion(outNumber[i].beichushu) << " = " << cinNumber << endl;
			}
		}
	}
}