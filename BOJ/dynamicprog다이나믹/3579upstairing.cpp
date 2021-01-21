#include <iostream>
#include <algorithm>
using namespace std;

int arr[300];
int D[300][3];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n == 1)
	{
		cout << arr[0];
		return (0);
	}
	D[0][1] = arr[0]; // 1st stair
	D[0][2] = 0;
	D[1][1] = arr[1];
	D[1][2] = arr[0] + arr[1];
	for (int i = 2; i < n; i++)
	{
		D[i][1] = max(D[i - 2][1], D[i - 2][2]) + arr[i];
		D[i][2] = D[i - 1][1] + arr[i];
	}
	cout << max(D[n - 1][1], D[n - 1][2]);

}
