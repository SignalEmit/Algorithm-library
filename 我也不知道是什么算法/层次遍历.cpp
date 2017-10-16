#include<iostream>
#include<string>
using namespace std;
class Node
{
private:
	Node *Left;
	Node *Right;
	int data;
public:
	Node(int data_, Node *Left_ = NULL, Node *Right_ = NULL):data(data_), Left(Left_), Right(Right_){}
	int dataNumber()
	{
		return data;
	}
	Node *&lf()
	{
		return Left;
	}
	Node *&ri()
	{
		return Right;
	}
	~Node()
	{
		delete Left;
		delete Right;
	}
};

void di(Node *root)
{
	if (root != NULL)
	{
		cout << root->dataNumber() << endl;
		di(root->lf());
		di(root->ri());
	}
}
int Work(Node *root, string &str)
{
	if (root != NULL && !str.empty() && str.at(0) == 'L')
	{
		str.erase(0, 1);
		Work(root->lf(), str);
	}
	else if (root != NULL && !str.empty() && str.at(0) == 'R')
	{
		str.erase(0, 1);
		Work(root->ri(), str);
	}
	else if (root != NULL)
	{
		return root->dataNumber();
	}
	else
		return -1;
}
int main()
{
	Node chile_one(1);
	Node chile_two(2);
	Node chile_seven(7);

	Node chile_downfour( 4 , NULL, &chile_one);
	Node chile_thridteen(13,NULL,NULL);
	Node chile_eleven(11,&chile_seven,&chile_two);
	Node chile_upfour(4,&chile_eleven,NULL);
	Node chile_eight(8,&chile_thridteen,&chile_downfour);
	Node chile_root(5,&chile_upfour,&chile_eight);

	while (1)
	{
		string s;
		cout << "请输入树的路径:";
		cin >> s;
		cout << "结果是："<<Work(&chile_root, s)<<endl;
	}
	system("pause");

}