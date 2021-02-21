#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	//cout << arr[0] << arr[1] << "\n";
	int max = 0;
	int tempc;
	for (int i = n - 1; i >= 0; i--)
	{
		tempc = n - i; // n - n + 1
		if (max < arr[i] * tempc)
		{
			max = arr[i] * tempc;
		}
	}
	cout << max;
}
