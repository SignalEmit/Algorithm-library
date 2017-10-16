/*С�������������������ӣ��ϴ�д����� �϶��ж����� ����...�� ������Ȼ�ͽ�С���ˡ�
����һ�죬С���������С���ֵ�����ȥ��԰��ˣ����԰������ľ�ܶ࣬�кܶ�ط����Բ��� �������Ǿ�����׽�Բء��������ֵĲ�ȭ�󣬵�һ����С���������������ˣ���Ϸ����ܼ򵥣�
����ֻҪС�������ڹ涨��ʱ�����ҵ����Ǿ���С����ʤ�����ұ����ֵ������˲�ȭ����˭����һ�ָ������ˣ�����ڹ涨��ʱ����ֻ�ҵ�һ���ˣ���ôû�б����ֵ��˻�ʤ�����ҵ�������һ�ָ������ˣ�����ڹ涨��ʱ����һ���˶�û���ҵ�����С��ʧ���ˣ���һ�ֻ����������ˡ�����С����֪�����ڹ涨ʱ���ڣ��Լ��Ƿ�����ҵ����е��ˣ�����������������æ����һ�¡�
����Ϊ�˼�������ѹ�԰������n��m�еľ������С�S����ʾС������D����ʾ��������E����ʾ��������X����ʾ�ϰ����.����ʾͨ·��������ǰѷ��ֶ���Ϊ������ֱ�ӿ����Է��� Ҳ����˵��������ͬһ�л���ͬһ�У������м�û���ϰ������û�������˾Ϳ��Կ����Է������Ҽ��裬�����������غ��Ժ�Ͳ����ٸı�λ�ã�С��ÿ����λʱ����Դӵ�ǰ��λ���ߵ����ڵ��ĸ�λ��֮һ�����Ҳ����߳���԰��
Input
�������ݵ�һ����һ��������T����ʾ��T��������ݡ�
ÿһ�������������������������n,m,t���ֱ��ʾ�����������͹涨��ʱ�䣬������n�У�ÿ��m���������ַ������ұ�֤����ֻ��һ����S����һ����E����һ����D����

[Technical Specification]
T < 200
3 <= n, m <= 100
0 <= t <= 100
Output
ÿ�������һ��Case c:(c��ʾ��ǰ����������1��ʼ����)��
������һ�У����С�������ڹ涨ʱ�����ҵ����е��ˣ������������Ҫ��ʱ�䣬�������-1��
Sample Input
3
5 6 6
XXD...
....E.
....X.
....S.
......
5 6 3
XDX...
....E.
......
....S.
......
5 6 8
XXDX..
EX.X..
......
....S.
......
Sample Output
Case 1:
-1
Case 2:
3
Case 3:
-1
1
7 7 19
S......
.X.....
..X....
...X...
....X..
.....XD
......E
res : 18

43 44 20
.XX.......X.....X.........X.........XXX....
........X.......X...........X..........XXX.
..X....X..X.X....X....X..X..X....X..X.....X
X.XX......X..X......X......X.XX...X.......X
.X....XX..X....X.X..X......X..X.XX.X..X....
XX.X....XX....................XX.XX.....X..
....X.X..X......XX..XXX.X.XX.X.X.X...X.....
..X....XX.X..XXXX.X...X...X........X..XX...
.........X.XX......S.........X........XX.X.
...X..X.X...X..E.XX....X....XX........X..X.
X....X...X...X...XX.....X......X.....X.X...
XX.....XX.X..X..XX.X.....XX...X....X......X
..XX...X.X...X.....X..X..X.X...XX.X..XXXX.X
XX..X.X.......X..X.....D...X...X.XXX..X...X
XX.....X..X...X....X.X.....................
.XX.X...X....XXX....XX..X.X...X...X..XX..X.
...XXX.X..X.XX.......XX.X..XX...XX.....X...
XXXX.......X......X.XXXX...X...X.X......XX.
..X....XXX...X........X...X.......X......X.
....X..X.X.X..XX...XX...X.....X.X.......XX.
....X.........XX.XX..X....XX...............
.......XXX..X.....X.........X..............
X.....X..X.X.X.........X.X...X.....XXX....X
..X..........X.X..X.X.XX......X...........X
.XX..XX.XX...XXX...X......X.X.XX.X....X..XX
.......X....XX....XX.XX..X..XX.X.X.........
X.....X......X...X..X.X..X..X.X...XX.XXX.XX
..X.X.........X....X........X.XXX.......X..
.X.X...X....XXX.XX.X.....X..X.X.........X.X
X.XXXX...X...X.............X......X......X.
.XX....X.X....X.....X..X...........X.X...X.
X.X...X..X.X.XXXX..........XX.X.......XX...
...X.X.X.X........X...........X......X..XX.
XX.XX.X...X...X.X.X.X...XX..XXX...X......XX
......X........X....XX.X...X......XXXX....X
.........XX.........X..X....X.X..X......X..
.......X.........X.X..X........X.....X...X.
X..X.X...X.........X.X..X...X.......X.....X
..X..X....X...................X...X.......X
X..X.......X...X.X....XX..X........X.XX....
.................X....X.....X...X..........
X.XX.X....XX.X..X.X.......X...XXX.X........
XX...X......X.X.....XXXX........X..X.X...X.
.....XXXXX...X...X.........XX...X...XXX....
case 5:13
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
	int x;
	int y;
	char data;
	void print(int x_, int y_, char data_) { x = x_; y = y_, data = data_; }
};
struct walk_location
{
	int x;
	int y;
	void print(int x_, int y_)
	{
		x=x_; 
		y = y_;
	}
};
walk_location GOGO[4]; 
queue<Node> NodeQueue;
vector<Node> son;
char map[101][101];
bool Judge[101][101];
bool findMan[2];
Node firstMing, secondMing, endMing;
int N, X_Number, Y_Number, WalksTimes;
int times = 0;
vector<int> jishuqi;
bool walik_judge(const Node &xiaoming,const walk_location &walk_)
{
	if (xiaoming.x + walk_.x >= 0 && xiaoming.x + walk_.x < X_Number && xiaoming.y + walk_.y>=0 && xiaoming.y + walk_.y < Y_Number  && !Judge[xiaoming.x + walk_.x][xiaoming.y + walk_.y] && (map[xiaoming.x + walk_.x][xiaoming.y + walk_.y] == 'S' || map[xiaoming.x + walk_.x][xiaoming.y + walk_.y] == '.'))
		return true;
	else
		return false;
}
void update(int o,int s)
{
	while (!NodeQueue.empty())
		NodeQueue.pop();
	son.clear();
	for (int i = 0; i < Y_Number; i++)
		for (int o = 0; o < X_Number; o++)
			Judge[o][i] = false;

	Judge[o][s] = true;
}
bool Judgenidaye(int panduan, int first, int end,int x,int y,char s)
{
	if (panduan==1)
	{
		for (int i = first; i <= end; i++)
			if (map[i][y] == 'X' || map[i][y] == s)
				return false;
	}
	else
	{
		for (int i = first; i <= end; i++)
			if (map[x][i] == 'X' || map[x][i] == s)
				return false;
	}
	return true;
}
void BFS(int ppp)
{
	while(!NodeQueue.empty())
	{
		if (map[firstMing.x][firstMing.y]!='X' && NodeQueue.front().x == firstMing.x && Judgenidaye(0, min(NodeQueue.front().y, firstMing.y) + 1, max(NodeQueue.front().y, firstMing.y) - 1, firstMing.x, firstMing.y, 'E'))
		{
			int x = NodeQueue.front().x, y = NodeQueue.front().y;
			map[firstMing.x][firstMing.y] = 'X';
			findMan[0] = true;
			if (findMan[0] && findMan[1])
			{
				cout << "Case " << ppp << ":" << endl;
				cout << times << endl;
				return;
			}
			update(NodeQueue.front().x, NodeQueue.front().y);
			Node w;
			w.print(x, y, 'p');
			NodeQueue.push(w);
		}
		if (map[firstMing.x][firstMing.y] != 'X' && NodeQueue.front().y == firstMing.y && Judgenidaye(1, min(NodeQueue.front().x, firstMing.x) + 1, max(NodeQueue.front().x, firstMing.x) - 1, firstMing.x, firstMing.y, 'E'))
		{
			int x = NodeQueue.front().x, y = NodeQueue.front().y;
			map[firstMing.x][firstMing.y] = 'X';
			findMan[0] = true;
			if (findMan[0] && findMan[1])
			{
				cout << "Case " << ppp << ":" << endl;
				cout << times << endl;
				return;
			}
			update(NodeQueue.front().x, NodeQueue.front().y);
			Node w;
			w.print(x, y, 'p');
			NodeQueue.push(w);
		}
		if (map[secondMing.x][secondMing.y] != 'X' && NodeQueue.front().x == secondMing.x && Judgenidaye(0, min(NodeQueue.front().y, secondMing.y) + 1, max(NodeQueue.front().y, secondMing.y) - 1, secondMing.x, secondMing.y, 'D'))
		{
			int x = NodeQueue.front().x, y = NodeQueue.front().y;
			map[secondMing.x][secondMing.y] = 'X';
			findMan[1] = true;
			if (findMan[0] && findMan[1])
			{
				cout << "Case " << ppp << ":" << endl;
				cout << times << endl;
				return;
			}
			update(NodeQueue.front().x, NodeQueue.front().y);
			Node w;
			w.print(x, y, 'p');
			NodeQueue.push(w);
		}
		if (map[secondMing.x][secondMing.y] != 'X' && NodeQueue.front().y == secondMing.y && Judgenidaye(1, min(NodeQueue.front().x, secondMing.x) + 1, max(NodeQueue.front().x, secondMing.x) - 1, secondMing.x, secondMing.y, 'D'))
		{
			int x = NodeQueue.front().x, y = NodeQueue.front().y;
			map[secondMing.x][secondMing.y] = 'X';
			findMan[1] = true;
			if (findMan[0] && findMan[1])
			{
				cout << "Case " << ppp << ":" << endl;
				cout << times << endl;
				return;
			}
			update(NodeQueue.front().x, NodeQueue.front().y);
			Node w;
			w.print(x, y, 'p');
			NodeQueue.push(w);
		}
		for(int i=0;i<4;i++)
			if (walik_judge(NodeQueue.front(), GOGO[i]))
			{
				Judge[NodeQueue.front().x + GOGO[i].x][NodeQueue.front().y + GOGO[i].y] = true;
				Node s;
				s.print(NodeQueue.front().x + GOGO[i].x, NodeQueue.front().y + GOGO[i].y,'p');
				son.push_back(s);
			}
		NodeQueue.pop();
		if (NodeQueue.empty())
		{
			while (!son.empty())
			{
				NodeQueue.push(*son.begin());
				son.erase(son.begin());
			}
			times++;
			if(times > WalksTimes)
			{
				cout <<"Case "<<ppp<<":"<<endl;
				cout << -1 << endl;
				return;
			}
		}
	} 
}
int main()
{
	GOGO[0].print(0, -1); GOGO[1].print(0, 1); GOGO[2].print(-1, 0); GOGO[3].print(1, 0);
	cin >> N;
	char lllll;
	for (int i = 0; i < N; i++)
	{
		times = 0;
		findMan[0] = false;
		findMan[1] = false;
		son.clear();
		while (!NodeQueue.empty())
			NodeQueue.pop();
		cin >> Y_Number >> X_Number >> WalksTimes;
		for (int s = 0; s < Y_Number; s++)
			for (int o = 0; o < X_Number; o++)
			{
				cin >> lllll;
				map[o][s] = lllll;
				Judge[o][s] = false;
				if (map[o][s] == 'S')
				{
					endMing.print(o, s, 'S');
					Judge[o][s] = true;
				}
				else if (map[o][s] == 'D')
					firstMing.print(o, s, 'D');
				else if (map[o][s] == 'E')
					secondMing.print(o, s, 'E');
			}
		NodeQueue.push(endMing);
		BFS(i+1);
	}
}