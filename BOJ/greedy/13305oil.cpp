#include <iostream>
using namespace std;

int length[100001];
int price[100001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
		cin >> length[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];

	int exp = 0;
	int dest = 0;
	unsigned long long total = 0;
	for (int i = 0; i < n - 1; i++)
	{
		exp = 0;
		dest = 0;
		for (int j = i; j < n; j++)
		{
			if (price[i] <= price[j])
			{
				dest += length[j + 1];
				exp++;
			}
			else
			{
				break;
			}

		}
		total += (unsigned long long)(price[i] * dest);
		//cout << total << " " << price[i] << "\n";
		if (exp != 0)
			i += exp - 1;
	}
	cout << total;
}
/*
4
3 3 4
1 1 1 1
*/
