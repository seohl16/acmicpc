#include <iostream>
using namespace std;

typedef long long ll;

int main(void)
{
	ll n;
	cin >> n;
	if (n == 1 | n == 2)
	{
		cout << '1';
		return (0);
	}
	ll a, b;
	a = b = 1;
	ll i;
	i = 3;
	ll tpa, tpb;
	while (i < n)
	{
		tpa = a + b;
		tpb = a;
		a = tpa;
		b = tpb;
		i++;
	}
	cout << a + b;
}
