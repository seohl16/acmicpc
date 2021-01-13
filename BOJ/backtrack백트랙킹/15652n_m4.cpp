#include <iostream>
using namespace std;

int arr[8];
int cnt[9];

void	dfs(int lev, int n, int m, int prev)
{
	if (lev == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n"; // endl일 때는 시간초과남 endl은 버퍼를 flush 하는 것을 겸합니다. \
		endl이 호출되면 출력한 내용이 실제로 출력 스트림에 반드시 완전히 넘어가게끔 하는 과정이 있기 때문에 느립니다.
		return ;
	}
	for (int i = prev; i <= n; i++)
	{
		arr[lev] = i;
		dfs(lev + 1, n, m, i);
	}
}

int main(void)
{
	int n;
	int m;

	cin >> n >> m;
	for (int i = 0; i< 9; i++)
		cnt[i] = 0;
	dfs(0, n, m, 1);

}
