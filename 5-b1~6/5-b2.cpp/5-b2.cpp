/*2352467 ут╟╒г© пе08*/
#include<iostream>
using namespace std;
int main()
{
	int light[100] = { 0 };
	int i = 0, j = 0, n = 1;
	for (i = 1; i <= 100; i++)
	{
		for (j = i, n = 1; j <= 100; j = i * n)
		{
			light[j - 1] += 1;
			n++;
		}
	}
	for (i = 0; i < 100; i++)
	{
		if (light[i] % 2 == 1)
			cout << i+1 << " ";
	}
	return 0;
}