#include <iostream>
using namespace std;

int arr[1005][1005];

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				continue ;
			else if (i == 1 && j != 1)
				arr[i][j] += arr[i][j - 1];
			else if (i != 1 && j == 1)
				arr[i][j] += arr[i - 1][j];
			else
				arr[i][j] += max(arr[i][j - 1], arr[i - 1][j]);
		}
	}
	cout << arr[n][m];
	return (0);
}



// int main(void)
// {
// 	int n, m; // 1 ~ 1000
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= m; j++)
// 			cin >> arr[i][j];
// 	}
// 	if (n == 1 && m == 1)
// 	{
// 		cout << arr[n][m];
// 		return (1);
// 	}
// 	int maxsum = 0;
// 	Node node, temp;
// 	node.y = 1;
// 	node.x = 1;
// 	node.candyn = arr[1][1];
// 	que.push(node);
// 	while (!que.empty())
// 	{
// 		node = que.front();
// 		que.pop();
// 		for (int i = 0; i < 3; i++)
// 		{
// 			temp.y = node.y + keyy[i][0];
// 			temp.x = node.x + keyy[i][1];
// 			if (temp.y <= n && temp.x <= m)
// 			{
// 				//cout << temp.y << temp.x << temp.candyn<< "a\n";
// 				temp.candyn = node.candyn + arr[temp.y][temp.x];
// 				que.push(temp);
// 			}

// 		}
// 		if (maxsum < temp.candyn)
// 			maxsum = temp.candyn;
// 	}
// 	cout << maxsum;
// 	return (1);
// }
