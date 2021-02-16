#include <iostream>
using namespace std;

int arr[101];
int d[101];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	d[1] = arr[1];
	d[2] = arr[1] + arr[2];
	if (n == 1 || n == 2)
	{
		cout << d[2];
		return (0);
	}
	for (int i = 3; i <= n ; i++)
	{
		d[i] = max(d[i - 3] + arr[i - 1] + arr[i], d[i - 2] + arr[i]);
		d[i] = max(d[i - 1], d[i]);
	}
	cout << d[n];
}
