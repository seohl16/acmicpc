#include <iostream>
#include <algorithm>
using namespace std;

int A[51];
int B[51];

bool	compare(int a, int b)
{
	if (a <= b)
		return (0);
	return (1);
}

int main(void)
{
	int n;
	cin >> n; // 1~50

	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i  < n; i++)
		cin >> B[i];
	sort(A, A + n);
	sort(B, B+n, compare);

	// for (int i = 0; i  < n; i++)
	// 	cout << B[i];
	int sum = 0;
	for (int i = 0; i <n; i++)
	{
		sum += A[i] * B[i];
	}
	cout << sum ;
}

