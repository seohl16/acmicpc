#include <iostream>
using namespace std;

int arr[8];
int visited[8];
int printarr[8];

void	sort_up(int arr[8], int num) // sort(arr, arr+n) algorithm
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
				//cout << arr[i] << arr[j] << " ";
			}
		}
	}
}

void	dfs(int lev, int n, int m)
{
	if (lev == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << printarr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			//visited[i] = 1;
			printarr[lev] = arr[i];
			dfs(lev + 1, n, m);
			//visited[i] = 0;
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort_up(arr, n);
	dfs(0, n, m);
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << arr[i];
	// }
}
