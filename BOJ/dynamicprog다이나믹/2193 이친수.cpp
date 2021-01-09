//boj #2193 예를 들면 1, 10, 100, 101, 1000, 1001 등이 이친수가 된다. 
//하지만 0010101이나 101101은 각각 1, 2번 규칙에 위배되므로 이친수가 아니다. 
#include <iostream>
using namespace std;

typedef long long ll;

int main(void)
{
	ll n;
	ll a, b;
	ll i;
	cin >> n;
	if (n == 1 || n == 2)
	{
		cout << '1';
		return (0);
	}
	ll tpa, tpb;
	a = b = 1;
	i = 3;
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