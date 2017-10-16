#include<iostream>
#include<string>
#include<list>
using namespace std;
class charNumber
{
public:
	char c;				//字符
	int number;			//个数
public:
	charNumber(char c_)
	{
		c = c_;
		number = 0;
	}
	void Plus_Number()
	{
		number++;
	}
	void show()
	{
		cout << "输出的字符是：" << c << "  " << "个数是：" << number << endl;
	}
};
class Str_Work
{
public:
	string str;							//字符
	int str_length;						//字符串长度
	list<charNumber> CharNumberList;
public:
	Str_Work(string str_)
	{
		str = str_;
		str_length = str_.size();
		for (int i = 0; i < str_.size(); i++)
		{ 
			bool Judge = false;
			auto findWalk = CharNumberList.begin();

			while(findWalk!= CharNumberList.end())
			{
				if (findWalk->c == str_.at(i))
				{
					findWalk->Plus_Number();
					Judge = true;
					break;
				}
				else
					findWalk++;					//指针下移
			}
			
			/**************初始化并更新******************/
			if (!Judge)
			{
				charNumber newCharNumber(str_.at(i));
				newCharNumber.Plus_Number();
				CharNumberList.push_back(newCharNumber);
			}
				

			
		}
	}
	void run(string str_Need)
	{
		auto findWalk = CharNumberList.begin();
		while (findWalk != CharNumberList.end())
		{
			findWalk->show();
			findWalk++;					//指针下移
		}
	}

};

int main()
{
	list<Str_Work> DictionaryList;
	string sample;
	while (cin >> sample)
	{
		if (sample != "!")
		{
			Str_Work  str_work(sample);					//分析
			DictionaryList.push_back(str_work);
		}
		else
			break;
	}

	/********************************输入需比对的数**********************/
	list<Str_Work> workstrList;
	int CountNumber = 0;
	string calculate[100];
	while (cin >> sample)
	{
		if (sample != "!")
		{ 
			Str_Work  str_work(sample);
			workstrList.push_back(str_work);
			calculate[CountNumber] = sample;
			CountNumber++;
		}
			
		else
			break;
	}


	
	for (auto sss = DictionaryList.begin(); sss != DictionaryList.end();sss++)							//遍历字典
	{
		
		for(auto aaa = workstrList.begin(); aaa != workstrList.end();aaa++)								//遍历需比对的
		{
			if (sss->str_length == aaa->str_length)														//如果长度相等
			{
				
				
				for(auto bidui_sss = sss->CharNumberList.begin();bidui_sss != sss->CharNumberList.end(); bidui_sss++)			//比对字典中的某一个
				{
					bool Judge[20];

					for (int i = 0; i < sss->str_length; i++)
						Judge[i] = false;

					int count = 0;
					for (auto bidui_aaa = aaa->CharNumberList.begin(); bidui_aaa != aaa->CharNumberList.end(); bidui_aaa++)
					{
						auto Judge_aaa = aaa->CharNumberList.end();
						Judge_aaa--;
						if (bidui_aaa->c == bidui_sss->c	&&	bidui_aaa->number == bidui_sss->number	&&	bidui_aaa == Judge_aaa)
						{
							Judge[count++] = true;
						}
						else
							break;
					}

					for (int i = 0; i < sss->str_length; i++)
						if (!Judge[i])
						{
							cout << "匹配失败" << sss->str<<endl;
							break;
						}
						else
						{
							if (i == sss->str_length-1	&&	Judge[i])
								cout << sss->str << "匹配成功";
						}
				}
			
			}
			else
			{
				cout << sss->str << "不匹配";
			}

		}
	}


	system("pause");
}