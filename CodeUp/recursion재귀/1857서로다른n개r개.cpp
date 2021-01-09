#include <iostream>
using namespace std;

int	recurs(int n, int r)
{
	if (n < r)
		return (0);
	if (r == 1)
		return (n);
	else if (n == r)
		return (1);
	return (recurs(n - 1, r - 1) + recurs(n - 1, r));
}

int main(void)
{
	int n;
	int r;

	cin >> n >> r;

	cout << recurs(n, r);
}
