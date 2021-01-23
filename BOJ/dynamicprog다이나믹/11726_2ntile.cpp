#include <iostream>
using namespace std;

int bucket[1000];
int ret;

int		f(int n)
{
	if (n == 0)
		return (0);
	if (bucket[n])
		return bucket[n];
	bucket[n] = (f(n - 1)%10007 + f(n - 2)%10007) % 10007;
	return bucket[n];
}

int main(void)
{
	int n;
	cin >> n;
	bucket[1] = 1;
	bucket[2] = 2;
	ret = f(n);
	cout << ret % 10007;
}
