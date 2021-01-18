#include <iostream>
using namespace std;

int arr[21];
int visited[21];
int maxbud;
int b;
int n;

void	sort_up(int arr[21], int num) // sort(arr, arr+n) algorithm
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

void	bcv(int prev, int sum)
{
	if (sum > b)
	{
		if (maxbud < sum - prev)
			maxbud = sum - prev;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i] )
		{
			visited[i] = 1;
			bcv(arr[i], sum + arr[i]);
			visited[i] = 0;

		}
	}

}

int main(void)
{
	cin >> b >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort_up(arr, n);
	maxbud = 0;
	//cnt = 0;
	bcv(0, 0);
	cout << maxbud;
}
