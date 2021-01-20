#include <iostream>
using namespace std;

int arr[9];
int printarr[9];
int cnt;

void	sort_up(int arr[9], int num) // sort(arr, arr+n) algorithm
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

void bck(int lev, int sum, int idx, int n)
{
	if (idx > 9 || lev > 7 || sum > 100)
		return ;
	if (lev == 7 && sum == 100)
	{
		if (cnt == 1)
		{
			for (int i = 0; i < n; i++)
				cout << printarr[i] << "\n";
			cnt = 0;
		}
		return ;
	}
	bck(lev, sum, idx + 1, n);
	printarr[lev] = arr[idx];
	bck(lev + 1, sum + arr[idx], idx + 1, n);
}

int main(void)
{
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort_up(arr, 9);
	cnt = 1;
	bck(0, 0, 0, 7);
}

/*
8
9
10
11
12
24
26
23
27
*/
