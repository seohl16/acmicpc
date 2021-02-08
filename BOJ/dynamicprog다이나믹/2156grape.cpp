#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int dp[10001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	if (n <= 2)
	{
		cout << dp[2];
		return (0);
	}
	// dp[3] = max(arr[1] + arr[3], dp[1] + arr[3]);
	// dp[3] = max(dp[2], dp[3]);
	for (int i = 3;i <= n; i++)
	{
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
		//i - 2 + i    i - 3 i - 1 i
		dp[i] = max(dp[i], dp[i - 1]);
		// 바로 직전, 지금 비교
	}
	cout << dp[n];
	return (0);
}

// int dp[10001][2];
// int main(void)
// {
// 	int n;
// 	cin >> n;

// 	for (int i = 1; i <= n; i++)
// 		cin >> arr[i];

// 	dp[1] = arr[1];
// 	dp[2] = arr[2];
// 	dp[2] = arr[1] + arr[2];
// 	if (n <= 2)
// 	{
// 		cout << dp[2];
// 		return (1);
// 	}
// 	dp[3] = arr[1] + arr[3];
// 	dp[3] = arr[2] + arr[3];
// 	for (int i = 4;i <= n; i++)
// 	{
// 		dp[i] = max(dp[i], dp[i]) + arr[i];
// 		dp[i] = max(dp[i], dp[i]) + arr[i];
// 	}

// 	for (int i = 1; i <=n; i++)
// 		cout << dp[i] << " " << dp[i] << "\n";
// 	int max1 = max(dp[n ][0], dp[n ][1]);
// 	int max2 = max(dp[n], dp[n]);
// 	cout << max(max1, max2);
// }
/*
6
1000 1000 1 1 1000 1000
output : 3001
answer : 4000

6
6 10 13 9 8 1
answer : 33

내가 직접 찾은 반례 ㅋㅋㅋ
3 4 5 6
(3일 때 제대로 처리 안하면 오류 남 )
	// dp[3] = max(arr[1] + arr[3], dp[1] + arr[3]);
	// dp[3] = max(dp[2], dp[3]);
*/
