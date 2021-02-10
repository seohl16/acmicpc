#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int num, end, cnt;

	num = 1;
	cnt = 0;
	while (num != 0)
	{
		cin >> num;
		if (num == 0)
			break;

		cnt = 0;
		end = sqrt(num);
		for (int i = 1; i <= end; i++)
		{
			if (i * i == num)
			{
				cnt++;
				continue ; // necessary
			}
			for (int j = i; j <= end; j++)
			{
				if (i * i + j * j == num)
				{
					cnt++;
					break; // necessary
				}
				else if (i * i + j * j > num)
					break;
				for (int k = j; k <= end; k++)
				{
					if (i * i + j * j + k * k == num)
					{
						cnt++;
						break;//necessary
					}
					else if (i * i + j * j + k * k > num)
						break;
					for (int l = k; l <= end; l++)
					{
						if (i * i + j * j + k * k + l * l == num)
						{
							cnt++;
							break;
						}
						else if (i * i + j * j + k * k + l * l > num)
							break;
					}

				}
			}
		}
		cout << cnt << "\n";
	}
}
