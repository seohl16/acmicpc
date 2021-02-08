#include <iostream>
using namespace std;

int arr[501][501];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
	}
	//cout << 501 * 250;
	int max;
	int sum;
	int idx;
	sum = arr[0][0];
	idx = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (arr[i + 1][j] > arr[i + 1][j + 1])
				arr[i][j] += arr[i + 1][j];
			else
			{
				arr[i][j] += arr[i + 1][j + 1];
			}

		}
	}
	//cout << "\n";
	cout << arr[0][0];
}

