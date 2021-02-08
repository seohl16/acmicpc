#include <iostream>
using namespace std;

int coinn[101];
//int d[101][10001];
int d[10001];
int dprev[100001];

int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> coinn[i];

	for (int i = 1; i <= n; i++)
	{
		d[0] = 1;
		for (int j = 1; j <= k; j++)
		{
			if (j >= coinn[i])
				d[j] = dprev[j] + d[j - coinn[i]];
			else
			{
				d[j] = dprev[j]; // d[j] += d[j - coins[i]];
			}
			dprev[j] = d[j];
		}
	}
	// for (int i = 1; i <= k ;i ++)
	// {
	// 	cout << d[i] << " ";
	// 	//cout << "\n";
	// }
	cout << d[k];
}
/*
3 10
1
2
5
1 1 1 1 1 1 1 1 1 1
1 2 2 3 3 4 4 5 5 6
1 2 2 3 4 5 6 7 8 10
10%
*/
// #include <iostream>
// using namespace std;

// int coinn[101];
// int d[101][10001];

// int main(void)
// {
// 	int n, k;
// 	cin >> n >> k;
// 	for (int i = 1; i <= n; i++)
// 		cin >> coinn[i];

// 	//cout << coinn[2];
// 	for (int i = 1; i <=n; i++)
// 		d[i][0] = 1;
// 	//cout << d[2][0];
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= k; j++)
// 		{
// 			if (j >= coinn[i])
// 				d[i][j] = d[i - 1][j] + d[i][j - coinn[i]];
// 			else
// 			{
// 				d[i][j] = d[i - 1][j];
// 			}

// 		}
// 	}
// 	// for (int i = 1; i <=n ;i ++)
// 	// {
// 	// 	for (int j = 1; j <= k; j++)
// 	// 		cout << d[i][j] << " ";
// 	// 	cout << "\n";
// 	// }
// 	cout << d[n][k];
// }
