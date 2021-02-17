#include <iostream>
using namespace std;

//greedy!!!

int arr[11];

int main(void)
{
	int n, k;
	cin >> n >> k; //1~10 1 ~ 1000000000
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cnt;
	cnt = 0;
	for (int i = n - 1 ;i >= 0; i--)
	{
		if (arr[i] <= k)
		{
			cnt += k / arr[i];
			//cout << cnt << " ";
			k %= arr[i];
		}
		if (k == 0)
			break ;
	}
	cout << cnt;
}
/*
예제 1
10 4200
1
5
10
50
100
500
1000
5000
10000
50000
answer : 6


반례
1 1 1
0 이면 안되고 1


*/
