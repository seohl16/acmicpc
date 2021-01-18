#include <iostream>
using namespace std;

int cnt;
int preprev;

void	upstair(int lev, int prev, int preprev, int n)
{
	if (lev > n)
		return ;
	if (lev == n)
	{
		cnt++;
		return ;
	}
	if (prev != 3 && preprev != 3)
		upstair(lev + 3, 3, prev, n);
	upstair(lev + 1, 1, prev, n);
	upstair(lev + 2, 2, prev, n);
}

int main(void)
{
	int n;
	cin >> n;
	cnt = 0;
	upstair(0, 0, 0, n);
	cout << cnt;
}

	// if (prev == 3 || preprev == 3)
	// {
	// 	upstair(lev + 1, 1, prev, n);
	// 	upstair(lev + 2, 2, prev, n);
	// }
	// else
	// {
	// 	upstair(lev + 3, 3, prev, n);
	// 	upstair(lev + 1, 1, prev, n);
	// 	upstair(lev + 2, 2, prev, n);
	// }

/*
input : 7
output : 42
answer : 41


*/
