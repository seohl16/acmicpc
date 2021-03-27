#include "iostream"
using namespace std;

unsigned int dp[5002][5002];
unsigned int sumup[5002][5002];

int main(void)
{
	unsigned int n, m;
	cin >> n >> m;

	unsigned int sum, cha;
	dp[1][1] = 1;
	sumup[1][1] = 1;
	for (unsigned int i = 1; i <= n; i++)
	{
		dp[i][i] = 1;
		sumup[i][i] = 1;
		for (unsigned int j = 1; j <= i; j++)
		{
			dp[i][j] = (sumup[i - j][j] + dp[i][j] ) ;
			sumup[i][j] = (sumup[i][j - 1] + dp[i][j]) % 123456789;
			for (unsigned int k = i + 1; k <= m; k++)
				sumup[i][k] = sumup[i][i];
		}

	}
	cout << sumup[n][m];
}


	// for (unsigned int i = 1; i <= n; i++)
	// {
	// 	dp[i][i] = 1;
	// 	sumup[i][i] = 1;
	// 	for (unsigned int j = 1; j <= i; j++)
	// 	{
	// 		if (i == j)
	// 			dp[i][j] = 1;
	// 		else
	// 		{
	// 			for (int k = 1; k <= j; k++)
	// 				dp[i][j] += (dp[i - j][k] % 123456789)
	// 			dp[i][j] %= 123456789;
	// 		}
	// 	}

	// }
