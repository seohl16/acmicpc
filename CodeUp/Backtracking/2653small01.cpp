#include <iostream>
using namespace std;

int printarr[20];
int ret;

void	recv(int lev, int n, int prev)
{
	if (lev == n)
	{
		ret++;
		// for (int i = 0; i < n; i++)
		// 	cout << printarr[i];
		// cout << "\n";
		return ;
	}
	if (prev == 0)
		recv(lev + 1, n, 1);
	recv(lev + 1, n, 0);

}

int main(void)
{
	int n;
	cin >> n;
	ret = 0;

	recv(0, n, 0);
	cout << ret;
}
