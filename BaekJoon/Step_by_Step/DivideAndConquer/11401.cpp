#include <iostream>
using namespace std;

long long n, k;
long long p = 1000000007;


long long facto(unsigned long long n)
{
	long long rv = 1;
	for(int i = n; i >= 2; i--)
	{
		rv *= i;
		rv %= p;
	}
	return rv;
}

long long solve(long long _x, long long _p)
{
	if(_p == 1)
	{
		return _x % p;
	}
	else
	{
		long long tmp = solve(_x, _p/2);
		if(_p % 2)
		{
			tmp *= tmp;
			tmp %= p;
			tmp *= _x;
			tmp %= p;
			return tmp;
		}
		else
		{
			tmp *= tmp;
			tmp %= p;
			return tmp;
		}
	}
}


int main()
{
	cin >> n >> k;
	long long a = facto(n);
	long long b= facto(n - k) * facto(k);
	b %= p;
	long long c = a * (solve(b, p-2)) % p;
	cout << c;
}