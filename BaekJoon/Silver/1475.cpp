#include <iostream>
using namespace std;

int main()
{
	int num_set[9] = {0,};
	int n, tmp, max = 0;
	cin >> n;
	
	while(n != 0)
	{
		tmp = n % 10;
		n /= 10;
		if(tmp == 9) tmp = 6;
		num_set[tmp] += 1;
	}
	num_set[6] = (num_set[6] + 1) / 2;
	
	for(int i=0; i<9; i++)
	{
		max = num_set[i] > max ? num_set[i] : max;
	}
	cout << max;
}