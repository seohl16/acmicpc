#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int wi;
	int vi;
};

int n, W;
int maxsum;
int dp[105][100005];

Node arr[103];

void	sortup()
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].wi > arr[j].wi || (arr[i].wi == arr[j].wi && arr[i].vi > arr[j].vi))
			{
				Node temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/*
1.  dp 정의먼저 하기.

           dp[i][j] =  i번째 보석, j의 비용일때의 max값

2.  만약 i번째 보석을 사용하지 않는다면 dp[i-1][j] 값과 같다.

3.  만약 i번째 보석을 사용한다면, dp[i][j] = dp[i-1][j-W[i]] + C[i]

*/
void 	recv(int lev)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (j < arr[i].wi)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j - arr[i].wi] + arr[i].vi, dp[i - 1][j]);
			if (maxsum < dp[i][j])
				maxsum = dp[i][j];
		}
	}
}


int main(void)
{
	cin >> n >> W;
	for (int i = 1; i <= n; i++)
		cin >> arr[i].wi >> arr[i].vi;
	recv(0);
	cout << maxsum;

}

// void	dfs(int lev, int sum)
// {
// 	if (lev > W)
// 		return ;
// 	if (maxsum < sum)
// 	{
// 		//cout << lev << "a";
// 		maxsum = sum;
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (!visited[i])
// 		{
// 			visited[i] = 1;
// 			dfs(lev + arr[i].wi, sum + arr[i].vi);
// 			visited[i] = 0;
// 		}
// 	}
// }

// int main(void)
// {
// 	cin >> n >> W;
// 	for (int i = 0; i < n; i++)
// 		cin >> arr[i].wi >> arr[i].vi;
// 	maxsum = 0;
// 	dfs(0, 0);
// 	cout << maxsum;
// }

/*
15 100000
61803 5
62863 0
41632 3
12794 2
71324 8
55358 2
34870 8
41590 7
17928 0
24218 3
18426 0
65130 2
16478 2
93173 9
*/
