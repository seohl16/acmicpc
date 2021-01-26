#include <iostream>
using namespace std;

int arr[1002];
int boxx[1002];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	boxx[0] = 1;
	for (int i = 1; i < n; i++)
	{
		boxx[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				boxx[i] = max(boxx[i], boxx[j] + 1);
			}
		}
	}
	cout << *max_element(boxx, boxx + n);
}
