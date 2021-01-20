#include <iostream>
using namespace std;

int arr[20];
int cnt;

void	bck(int sum, int idx, int prev, int n, int k)
{
	//cout << sum << " " << idx << "   ";
	if (sum > n || idx > k) // idx >= k 라고 해서 에러 났었다.
		return ;
	else if (sum == n && idx < k )
		return ;
	if (sum == n && idx == k )
	{
		cnt++;
		//cout << "a ";
		return ;
	}
	if (prev == 0)
		bck(sum + arr[idx], idx + 1, 1, n, k);
	bck(sum + 1, idx, 0, n, k);
}


int main(void)
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	cnt = 0;
	bck(0, 0, 0, n, k);
	cout << cnt;
}
