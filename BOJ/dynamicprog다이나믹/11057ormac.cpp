#include <iostream>
using namespace std;

unsigned long long dp[1001][10];  // 0 1 2 3 4   5 6 7 8 9

int main(void)
{
	int n;
	cin >> n;
	unsigned long long sum = 0;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) // 1 2 3 4 ... n
	{
		for (int k = 0; k <= 9; k++)
		{
			sum = 0;
			for (int j = 0; j <= k; j++)
				sum += dp[i - 1][j];
			dp[i][k] = sum % 10007;
		}
		// dp[i][9] = dp[i - 1][0] + dp[i - 1][1] .... + dp[i - 1][9];
		// dp[i][8] = dp[i - 1][0] + dp[i - 1][1] ... + dp[i - 1][8];
		// ...
		// dp[i][0] = dp[i - 1][0];
	}
	sum = 0;
	for (int k = 0; k <= 9; k++)
		sum += dp[n][k];
	cout << sum % 10007;

}
