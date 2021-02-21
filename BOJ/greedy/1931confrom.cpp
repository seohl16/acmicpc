#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, int> >v;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void)
{
	int n;
	cin >> n; //1~100 000

	int start, finish;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> finish;
		v.push_back(make_pair(start, finish));
	}

	sort(v.begin(), v.end(), comp);
	//sort (s, s + n) second first를 반대로 하면 sort함수 그대로 써도 된다.
	// for (int i = 0; i < n; i++)
	// 	cout << v[i].first << v[i].second;
	// cout << "\n";
	int temp = 0; //v[0].first;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp > v[i].first)
			continue;
		cnt ++;
		temp = v[i].second;
	}
	cout << cnt;
}
/*
3
0 1000
998 1002
1001 2000
answer : 2

5
4 4
4 4
3 4
2 4
1 4
answer : 3
이건 sort자체를 안해서 틀렸던

6
2 13
3 5
3 4
3 3
4 7
4 6
answer : 3 temp < v[i].first 에서 <=를 고쳤다


*/
