#include "iostream"
using namespace std;

int dp[1000][1000];

int main(void)
{
	int n, m;
	cin >> n >> m; // 5 3

	int sum, cha;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for (int i = 4; i <= n; i++) // 4 5
	{
		dp[i][i] = 1;
		for (int j = 1; j <= i; j++) // 3까지  2~ 4
		{
			sum = 0;
			cha = i - j;
			for (int k = 1; k <= i - j; k++) // 4 - 2 ~ 2 dp[4][1][2][3][4]
				sum += dp[j][k];
			dp[i][i - j] = sum; // dp[5][1] = sum
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << dp[i][j] << " ";
		cout <<"\n";
	}
	sum = 0;
	for (int i = 1; i <= m; i++)
	{
		sum += dp[n][i];
	}
	cout << sum;
}

