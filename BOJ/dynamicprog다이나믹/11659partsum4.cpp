#include <iostream>
using namespace std;

int arr[100001];
int partsum[100001];


int main(void)
{
	//ios:sync~ 쓰면 cin cos 가능
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++)
	{
		partsum[i] = partsum[i - 1] + arr[i];
	}
	for (int j = 1; j <= m; j++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", partsum[b] - partsum[a - 1]);
		//cout << partsum[b] - partsum[a - 1] << "\n";
	}
}

//분명 같은 코드인데 cout cin을 쓰면 시간초과 난다
