//boj #2193 ���� ��� 1, 10, 100, 101, 1000, 1001 ���� ��ģ���� �ȴ�. 
//������ 0010101�̳� 101101�� ���� 1, 2�� ��Ģ�� ����ǹǷ� ��ģ���� �ƴϴ�. 
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