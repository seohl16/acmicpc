#include <iostream>
using namespace std;

int arr[9];
int memoz[100001];

int		recv(int n)
{
	if (memoz[n])
		return (memoz[n]);
	if (n == 1 || n == 2)
		return (n);
	if (n == 3)
		return (4);
	memoz[n]= recv(n - 3) %1000 + recv(n - 2)%1000 + recv(n - 1)%1000;
	return memoz[n];
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		cout << recv(arr[i]) << "\n";
	}
}
