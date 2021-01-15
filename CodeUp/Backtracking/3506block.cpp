#include <iostream>
using namespace std;

int ret;
int saved[30];

int		recv(int n)
{
	int ans;

	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (saved[n] != 0)
		return saved[n];
	ans = recv(n - 1) + recv(n - 2);
	saved[n] = ans;
	return (ans);
}

int main(void)
{
	int n;
	cin >> n;

	ret = recv(n);
	cout << ret;
}
