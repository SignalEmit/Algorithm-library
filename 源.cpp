#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
pair<int, int> point[10001];    // 输入点
set<pair<int, int>> all;
int n;

void dfs(int l, int r)
{
	int mid = (l + r) >> 1, mid_x = point[mid].first;         // 分割线
	for (int i = l; i <= r; i++)
	{
		all.emplace(pair<int, int>(mid_x, point[i].second));  // 投影
	}
	if (l < mid)
	{
		dfs(l, mid - 1);
	}
	if (mid < r)
	{
		dfs(mid + 1, r);
	}
}

int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d%d", &point[i].first, &point[i].second);
	}
	sort(point, point + n);
	dfs(0, n - 1);
	printf("%d\n", all.size());
	for (auto &p : all)
	{
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}