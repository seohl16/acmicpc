#include <iostream>
using namespace std;

int arr[20];
int visited[20];
int ret;

void dfs(int lev, int n, int s, int sum)
{
	sum += arr[lev];

	if (lev >= n)
		return ;
	if (sum == s)
		ret++;
	dfs(lev + 1, n, s, sum - arr[lev]);
	dfs(lev + 1, n, s, sum);
}

int main(void)
{
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ret = 0;
	dfs(0, n, s, 0);
	cout << ret;
}
