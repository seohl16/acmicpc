#include <iostream>
#include <queue>
using namespace std;

int board[25][25];
int visited[25][25];
int num_dan[25];

struct Node
{
	int y;
	int x;
	int lev;
};

queue <Node> que;

void	print_changed(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int bfs(int y, int x, int lev, int n)
{
	Node node, temp;
	int newx, newy;
	int cnt;
	int arr[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

	que.push({y, x, lev});
	cnt = 1;
	visited[y][x] = 1;
	while (!que.empty())
	{
		node = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			newy = node.y + arr[i][0]; // node.y 가 아닌 y를 써서 에러.
			newx = node.x + arr[i][1]; // 마찬가지.
			if (newy < 0 || newy >= n || newx < 0 || newx >= n)
				continue ;
			if (visited[newy][newx] >= 1 || board[newy][newx] == 0)
				continue ;

			visited[newy][newx] = 1;
			//print_changed(n, n);
			cnt++;
			temp = {newy, newx, lev};
			que.push(temp);

		}
	}
	return (cnt);

}

void	sort_up(int arr[25], int num) // sort(arr, arr+n) algorithm
{
	int tmp;

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int n;
	int awr;
	int ret;
	char str[30];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < n; j++)
			board[i][j] = str[j] - 48;
	}
	awr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 && visited[i][j] == 0)
			{
				ret = bfs(i, j, awr + 1, n);
				num_dan[awr] = ret;
				awr++;
			}
		}
	}
	cout << awr << "\n";
	sort_up(num_dan, awr);
	for (int i = 0; i < awr; i++)
		cout << num_dan[i] << "\n";
	return (0);
}
