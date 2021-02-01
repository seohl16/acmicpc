#include <iostream>
using namespace std;
long long dp[100001][4];
int main() {
	int T, temp;
	cin >> T;
	dp[1][1] = 1; dp[2][2] = 1;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}
	for (int i = 0; i < T; i++) {
		cin >> temp;
		cout << dp[temp][1] << dp[temp][2] << endl;
		cout << (dp[temp][1] + dp[temp][2] + dp[temp][3]) % 1000000009 << endl;
	}
}
// 이제 이해했다. [1][2][3]은 마지막에 더한 수를 의미
// 15990문제는 두 숫자가 이어서 나오면 안되는 문제였다.
// 따라서 i- 1일때는 +1하면되는데 이걸 [2][3] 즉 +2 +3 으로 끝난 애 뒤에다가 하겠다는 이야기!!
