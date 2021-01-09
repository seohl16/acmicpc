#include <iostream>
using namespace std;

void	g(int k)
{
	if (k == 0)
		return ;
	g(k - 1);
	cout << "*";
}

void	star(int num)
{
	if (num == 0)
		return ;
	star(num - 1);
	g(num);
	cout << endl;
	return ;
}

int main(void)
{
	int input;

	cin >> input;
	star(input);
}
