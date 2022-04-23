#include <iostream>
using namespace std;

//1st try
int bits[7] = {0, };

int sum_stick()
{
	int sum = 0;
	for(int i=0; i<7; i++) sum += bits[i] * (1 << i);
	return sum;
}

int main()
{
	bits[6] = 1; // 기존에 가지고 있는 막대기_64 : 2^6 == 1 << 6 (Bitwise)
	
	int x, sum, short_stick, cnt = 0;
	cin >> x;
	
	sum = sum_stick();
	
	while(x < sum)
	{
		for(int i=1; i<7; i++)
		{
			if(bits[i] > 0)
			{
				short_stick = i;
				bits[i] -= 1;
				bits[i-1] += 2;
				break;
			}
		}
		int drop_stick = (1 << (short_stick - 1));
		if((sum - drop_stick) >= x)
		{
			sum -= drop_stick;
			bits[short_stick - 1] -= 1;
		}
	}
	
	for(int i=0; i<7; i++) cnt += bits[i];
	cout << cnt;
	
	
}