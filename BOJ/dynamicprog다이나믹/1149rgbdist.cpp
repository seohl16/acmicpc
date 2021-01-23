#include <iostream>
using namespace std;

int board[1000][3];
int rg[1000][3];
int n;


int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int j = 0; j < 3; j++)
		rg[0][j] = board[0][j];

	for (int i = 1; i < n; i++)
	{
		rg[i][0] = min(rg[i - 1][1], rg[i - 1][2]) + board[i][0];
		rg[i][1] = min(rg[i - 1][0], rg[i - 1][2]) + board[i][1];
		rg[i][2] = min(rg[i - 1][0], rg[i - 1][1]) + board[i][2];
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << rg[i][0] << " " << rg[i][1] << " " << rg[i][2] << "\n";
	// }
	cout << min(min(rg[n - 1][0], rg[n - 1][1]), rg[n - 1][2]);
}
