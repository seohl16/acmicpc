#include <iostream>
using namespace std;

unsigned long memocc[61][61];
unsigned long memohh[61][61];

unsigned long nCr(int n, int k)
{
	if (memocc[n][k])
		return (memocc[n][k]);
	if (n == 0 || n == 1)
		return (1);
	if (k == 0 || k == n)
		return (1);
	memocc[n][k] = nCr(n-1, k-1)+ nCr(n-1, k);
	//cout << ans << "\n";
	return (memocc[n][k]);
}

unsigned long	nHr(int n, int r)
{
	if (memohh[n][r])
		return (memohh[n][r]);
	memohh[n][r] = nCr(n + r - 1, r);
	return (memohh[n][r]);
}

void recv(int n)
{
	unsigned long sum;

	sum = 0; // 안해서 에러 1
	for (int i = 2; i <= n; i++) // 2 3 4
	{
		sum += nHr(i, n - i);
		//cout << nHr(i, n - i) << "  ";
	}
	cout << sum;
}

int main(void)
{
	int n;
	cin >> n;
	//cout << "b" << nCr(3,2);

	recv(n);
	//cout << memohh[2][2];

}
