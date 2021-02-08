#include <iostream>
using namespace std;

struct testcase
{
	int n; // 1~20
	int mon; // 1 ~10000
	int coin[21];
};

int dp[10][10001];

int main(void)
{
	testcase arr[11];

	int t; // ~ 1
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> arr[i].n;
		for (int j = 0; j < arr[i].n; j++)
			cin >> arr[i].coin[j];
		cin >> arr[i].mon;
	}

	for (int x = 0; x < t; x++)
	{
		for (int i = 0; i < arr[x].n; i++)
		{
			dp[x][0] = 1;
			for (int j = 1; j <= arr[x].mon; j++)
			{
				if (j >= arr[x].coin[i])
					dp[x][j] += dp[x][j - arr[x].coin[i]];
			}
		}
		cout << dp[x][arr[x].mon] << "\n";
	}
	// for (int i = 0; i < arr[0].mon; i++)
	// 	cout << dp[0][i] << " ";
	// cout << dp[0][arr[0].mon];
}
