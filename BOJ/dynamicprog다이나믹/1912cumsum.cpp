#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int d[100005];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	d[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		d[i] = max(d[i -1], 0) + arr[i];
	}
	cout << *max_element(d + 1, d + n + 1);

}


// int main(void)
// {
// 	int n;
// 	cin >> n;

// 	int num; // input
// 	int inner_sum;
// 	int maxsum;

// 	cin >> num;
// 	if (n == 1)
// 	{
// 		cout << num;
// 		return (1);
// 	}
// 	inner_sum = num;
// 	maxsum = num;
// 	for (int i = 1; i < n; i++)
// 	{
// 		cin >> num;
// 		if (num >= 0) // update inner_sum
// 		{
// 			inner_sum += num;
// 		}
// 		else // num < 0 so update maxsum
// 		{
// 			if (inner_sum > maxsum)
// 				maxsum = inner_sum;
// 			inner_sum = 0;
// 		}

// 	}
// 	cout << maxsum;
// }
