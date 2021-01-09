#include <stdio.h>
#include <stdlib.h>
#define mod 1000000000

long long int dp[101][10];

long long int sol(int n, int i) {

	if (dp[n][i] != -1) return dp[n][i];
	else {
		if (i == 0) dp[n][i] = sol(n - 1, i + 1);
		else if (i == 9) dp[n][i] = sol(n - 1, i - 1);
		else dp[n][i] = (sol(n - 1, i - 1) + sol(n - 1, i + 1)) % mod;
	}


	return dp[n][i];
}

int main() {
	int n, i, j;
	long long int ans = 0;

	scanf("%d", &n);

	for (i = 0; i < 101; i++)
	{
		for (j = 0; j < 10; j++)
			dp[i][j] = -1;
	}

	dp[1][0] = 0;
	for (i = 1; i <= 9; i++)
		dp[1][i] = 1;

	//for (i = 0; i < 10; i++)
		//printf("dp[%d][%d] = %lld\n", n, i, sol(n, i));

	
	for (i = 0; i <= 9; i++) {
		ans += sol(n, i);
		ans %= mod;
	}

	printf("%lld", ans);
	

	return 0;

}