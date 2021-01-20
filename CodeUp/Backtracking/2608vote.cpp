#include <iostream>
using namespace std;

char arr[7];

void	bck(int lev, int n)
{
	if (lev == n)
	{
		for (int i = 0; i < n; i++)
			cout << arr[i];
		cout << "\n";
		return ;
	}
	arr[lev] = 'O';
	bck(lev + 1, n);
	arr[lev] = 'X';
	bck(lev + 1, n);
}

int main(void)
{
	int n;
	cin >> n;

	bck(0, n);
}
