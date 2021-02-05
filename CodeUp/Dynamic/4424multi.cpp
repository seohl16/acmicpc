#include <iostream>
using namespace std;

double arr[10005];
double dd[10005];

int main(void)
{
	int n;
	cin >> n;

	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

	}
	double max;
	dd[0] = 1;
	max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dd[i - 1] < 1)
			dd[i] = 1;
		else
			dd[i] = dd[i - 1];
		dd[i] *= arr[i];
		if (max < dd[i])
			max = dd[i];

	}
	printf("%.3f", max);
//	cout << max;
}
