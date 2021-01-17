#include <iostream>
using namespace std;

int ret;
int n, k;

void 	bk(int lev, int man, int prev)
{
	if (lev == n)
	{
		if (man == k)
		{
			ret++;
		}
		return ;
	}
	if (prev == 0)
		bk(lev + 1, man + 1, 1);
	bk(lev + 1, man, 0);
}

int main(void)
{
	//int n, k;
	cin >> n >> k;
	ret = 0;
	bk(0, 0, 0);
	cout << ret;
}
