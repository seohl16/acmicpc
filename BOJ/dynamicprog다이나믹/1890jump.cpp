#include <iostream>
using namespace std;

unsigned long arr[101][101];
unsigned long dp[101][101];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	}
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 && j == 1)
				continue;
			for (int k = 1; k < j; k++)
			{
				if (k + arr[i][k] == j)
				{
					dp[i][j] += dp[i][k];
				}
			}
			for (int k = 1; k < i; k++)
			{
				if (k + arr[k][j] == i)
					dp[i][j] += dp[k][j];
			}
		}
	}
	cout << dp[n][n] << "\n";
}
