#include <iostream>
#include <queue>
using namespace std;

int board[1000][1000];
int visited[1000][1000];

struct Node {
	int n; // y
	int m; // x
	int lev;
};

queue <Node> que;

void	add_ripe_init(int n, int m)
{
	Node temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1)
			{
				visited[i][j] = 1;
				temp.n = i;
				temp.m = j;
				temp.lev = 0;
				que.push(temp);
			}
			else if (board[i][j] == -1)
			{
				visited[i][j] = -1;
			}
			else
			{
				visited[i][j] = 0;
			}

		}
	}
}

int		check_ifall_ripe(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0)
			{
				return (0);
			}
		}
	}
	return (1);
}

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
}

int		bfs(int n, int m)
{
	Node node, temp;
	int nnn, mmm;
	int cnt = 8;
	int arrnn[4] = {-1,1,0,0};
	int arrmm[4] = {0,0,1,-1};

	while (!que.empty())
	{
		node = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			nnn = node.n + arrnn[i];
			mmm = node.m + arrmm[i];
			//visited[nnn][mmm] = 1;
			if (nnn < 0 || nnn >= n || mmm < 0 || mmm >= m)
				continue;
			if (board[nnn][mmm] == 1 || board[nnn][mmm] == -1)
				continue;
			if (visited[nnn][mmm] == 1)
				continue;
			visited[nnn][mmm] = 1;
			//cout << visited[nnn][mmm];
			temp.n = nnn;
			temp.m = mmm;
			temp.lev = node.lev + 1;
			que.push(temp);
			//print_changed(n, m);
		}
		if (check_ifall_ripe(n, m))
			return (node.lev + 1);
	}
	return (node.lev);
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	add_ripe_init(n, m);
	if (check_ifall_ripe(n, m))
	{
		cout << "0";
		return (0);
	}
	int ret = bfs(n, m);
	//print_changed(n, m);
	if (check_ifall_ripe(n, m))
	{
		cout << ret;
	}
	else
		cout << "-1";
	//Node node = que.front();
	//cout << node.lev;


}
