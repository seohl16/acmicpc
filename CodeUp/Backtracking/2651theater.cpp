#include <iostream>
using namespace std;

/// 파스칼의 삼각형으로 풀기 (재귀)(점화)

int nCr(int n, int k)
{
	if (n == 0 || n == 1)
		return (1);
	if (k == 0 || k == n)
		return (1);
	int ans = nCr(n-1, k-1) + nCr(n-1, k);
	//cout << ans << "\n";
	return (ans);
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	int ret = nCr(n, k);
	cout << ret;
}

/*
int main(void)
{
	int n, k;
	cin >> n >> k;

	int top = 1;
	for (int i = 0; i < k; i++)
	{
		top *= (n - i);
	}
	int bottom = 1;
	if (n - k < k)
		k = n - k;
	for (int i = k; i > 0; i--)
	{
		bottom *= (i);
	}
	cout << top <<" " <<  bottom;
	int answer = top / bottom;
	cout << answer;
}
위의 식으로 하면 25 13 을 감당 못한다.


*/
