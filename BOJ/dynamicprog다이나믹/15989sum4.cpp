#include <iostream>
using namespace std;

int arr[10005];
int dp[10005][3];

int main(void)
{
	int n, temp;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	for (int i = 4; i <= 10000; i++) // 10000이 아닌 n이라 해서 에러 ㅋㅋ
	{
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}
	for (int i = 1; i <= n; i++)
	{
		temp = arr[i];
		cout << dp[temp][0] + dp[temp][1] + dp[temp][2] << "\n";
	}
}

//그 전에 뭐로 끝나는지 따라 [1][2][3]이다.
// 오름차순으로 배열하면 중복 제거할 수 있는 원리 이용해서
// [1] 뒤에는 1만 올 수 있으므로 d[n][1] 은 d[n-1][1]이고
// [2] 뒤에는 2 랑 1 이 올 수 있으므로 d[n - 2][1] + d[n-2][2]이다.
// [3] 뒤는 3 2 1 다 오니까 d[n-3][1] + ~ d[n-3][3]이겠지
