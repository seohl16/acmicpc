#include <iostream>
using namespace std;

int cnt;

void	recv(int lev, int nowt, int goalt)
{
	if (cnt < lev || nowt < 0 || nowt > 40)
		return ;
	if (nowt == goalt)
	{
		if (cnt > lev)
			cnt = lev;
		return ;
	}
	recv(lev + 1, nowt - 10, goalt);
	recv(lev + 1, nowt + 10, goalt);
	recv(lev + 1, nowt - 5, goalt);
	recv(lev + 1, nowt + 5, goalt);
	recv(lev + 1, nowt - 1, goalt);
	recv(lev + 1, nowt + 1, goalt);
}

int main(void)
{
	int nowt, goalt;
	cin >> nowt >> goalt;
	cnt = 40;
	recv(0, nowt, goalt);
	cout << cnt;
}
