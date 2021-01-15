#include <iostream>
using namespace std;

int board[100][100];
int temp[100][100];
int visited[100][100];
int ans;

void	print_visited(int n, int k)
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void bfs(int i, int j, int k, int n)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return ;
	if (board[i][j] <= k)
		return ;
	board[i][j] = k;
	int arr[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
	for (int x = 0; x < 4; x++)
	{
		int newy = i + arr[x][0];
		int newx = j + arr[x][1];
		bfs(newy, newx, k, n);
	}
}

void	clear_visited(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
		//cout << "\n";
	}
}

int main(void)
{
	int n;
	int height;
	cin >> n;

	height = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			temp[i][j] = board[i][j];
			if (height < board[i][j])
				height = board[i][j];
		}
	}
	int max = 0;
	for (int k = 0; k < height; k++)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
//			ans = 0;
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] > k)
				{
					//visited[i][j] = 1;
					bfs(i, j, k, n);
					//visited[i][j] = 0;
					ans++;
				}
				board[i][j] = temp[i][j];
			}

		}
		if (max < ans)
				max = ans;
		//clear_visited(n);
	}
	cout << max;
}

/*
7
9 9 9 9 9 9 9
9 2 1 2 1 2 9
9 1 8 7 8 1 9
9 2 7 9 7 2 9
9 1 8 7 8 1 9
9 2 1 2 1 2 9
9 9 9 9 9 9 9

*/
