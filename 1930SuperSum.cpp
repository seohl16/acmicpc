#include <iostream>
#include <stdio.h>
using namespace std;

int bucket[15][15];

void init_bucket(void)
{
	for (int k = 0; k < 15; k++)
	{
		for (int n = 0; n < 15; n++)
		{
			if (k == 0)
				bucket[k][n] = n;
			else
				bucket[k][n] = 0;
		}
	}
}

int supersum(int k, int n)
{
	int sum;

	sum = 0;
	if (k == 0 || bucket[k][n] != 0)
		return (bucket[k][n]);
	for (int i = 1; i <= n; i++)
	{
		sum += supersum(k - 1, i);
	}
	if (bucket[k][n] == 0)
		bucket[k][n] = sum;
	return (sum);
}

int main(void)
{
	int k;
	int n;
	init_bucket();
	while (scanf("%d %d", &k, &n) != EOF)
		printf("%d\n", supersum(k, n));
}
