#include <iostream>
using namespace std;

int board[9][9];
int	cnt[9][9];
int d = 0;
int ret;

void	init_cnt()
{
	int i;
	int j;

	for (i = 0; i <= 8; i++)
	{
		for (j = 0; j <= 8; j++)
		{
			cnt[i][j] = 0;
		}
	}

}

void	input_board()
{
	int i;
	int j;

	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7; j++)
		{
			cin >> board[i][j];
		}
	}

}

int dfs(int i, int j)
{
	int newx;
	int newy;
	int arr[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

	if (i < 1 || i > 7 || j < 1 || j > 7)
	{
		return 0;
	}
	d++;
	cnt[i][j] = 1;
	for (int k = 0; k < 4; k++)
	{
		newx = i + arr[k][0]; //new
		newy = j + arr[k][1];
		if (board[newx][newy] == board[i][j] && cnt[newx][newy] == 0)
		{
			dfs(newx, newy);
		}
	}
	return (ret);
}

void	print_cnt()
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cout << cnt[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main(void)
{
	int i;
	int j;

	init_cnt();
	input_board();
	ret = 0;
	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7; j++)
		{
			d = 0;
			if (cnt[i][j] == 0)
			{
				dfs(i, j);
			}
			if (d >= 3)
			{
				//print_cnt();
				//cout <<i << j<< ret<<endl;
				ret++;
			}

		}
	}
	//print_cnt();
	cout << ret;
}
/*
4 4 4 4 1 4 3
4 4 4 4 3 2 4
4 4 4 4 5 5 4
4 4 4 4 2 1 3
5 5 3 2 4 4 4
2 1 1 3 4 4 4
5 4 5 5 4 4 4
answer : 2
4 1 3 1 5 3 4
2 5 4 1 2 5 2
1 5 4 4 2 4 5
4 5 1 2 4 5 2
5 5 5 3 5 1 5
5 1 1 2 4 4 2
4 2 4 2 3 3 5
answer : 2
*/
