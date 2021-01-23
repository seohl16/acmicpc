#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int num;
	int cnt;
};

queue <Node> que;

void bfs(int n, int lev)
{
	Node node, temp;
	node = { n, lev };
	que.push(node);
	while (1)
	{
		node = que.front();
		que.pop();
		if (node.num == 1)
			break;
		if (node.num % 3 == 0)
		{
			//temp = { node.num / 3, node.cnt + 1 };
			que.push({ node.num / 3, node.cnt + 1 });
		}
		if (node.num % 2 == 0)
		{
			que.push({ node.num / 2, node.cnt + 1 });
		}
		que.push({ node.num - 1, node.cnt + 1 });
	}
	cout << node.cnt;
}

int main(void)
{
	int n;
	cin >> n;
	bfs(n, 0);

}

//g++ -std=c++11 1463makingone.cpp;./a.out
