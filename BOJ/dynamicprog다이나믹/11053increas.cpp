#include <iostream>
#include <algorithm>
using namespace std;

int arr[1002];
int d[1002];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	d[0] = 1;
	for (int j = 1; j < n; j++)
	{
		d[j] = 1; // 없으면 틀림
		for (int i = 0; i < j; i++)
		{
			if (arr[i] < arr[j])
			{
				d[j] = max(d[j], d[i] + 1);
			}
		}
	}
	cout << *max_element(d + 0, d + n); // d + 1 틀림
}
