#include <iostream>
#include <queue>
using namespace std;

int board[1002][1002];
int visit[1002][1002];

struct Node
{
	int n; // y줄
	int m; // x줄
	int lev; //몇 번 건넜는지
};

queue <Node> que;

void print_visit(int n, int m) // 중복으로 들어가는지 확인 용도.
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << visit[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int bfs(int n, int m)
{
	int ndheight;
	int arr[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

	Node node, temp;
	node.n = 1;
	node.m = 1;
	node.lev = 1;
	que.push(node);
	while (!que.empty())
	{
		node = que.front();
		que.pop();
		if (node.n < 1 || node.m < 1 || node.n > n || node.m > m)
			continue ;
		if (node.n == n && node.m == m)
		{
			cout << node.lev;
			return (1); // 맞게 출력된 경우 return 1
		}
			//break ;
		ndheight = board[node.n][node.m];
		visit[node.n][node.m] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nnn = node.n + arr[i][0];
			int mmm = node.m + arr[i][1];
			if (nnn < 1 || nnn > n || mmm < 1 || mmm > m)//n이라 해서 틀린 적 있다.
				continue ;
			if (visit[nnn][mmm] == 0)
			{
				if (board[nnn][mmm] >= ndheight - 1 && \
				board[nnn][mmm] <= ndheight + 1)
				{
					visit[nnn][mmm] = 1;
					temp.n = nnn;
					temp.m = mmm;
					temp.lev = node.lev + 1;
					que.push(temp);
					//visit[nnn][mmm] = 0; // 필요 없다.
					//print_visit(n, m);
				}
			}
		}
		//visit[node.n][node.m] = 0; // 이게 시간초과 가장 큰 원인. 필요 없다.

	}
	return (0); // 1 4 \n 7 6 3 4 --와 같이 잘못된 풀이는 0이 나와야 한다.

}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}
	visit[1][1] = 1;
	int ret = bfs(n, m);
	if (ret == 0)
		cout << "0";
}
