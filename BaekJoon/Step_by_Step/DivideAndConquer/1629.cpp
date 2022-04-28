#include <iostream>
using namespace std;

long long a, b, c;

long long solve(long long n)
{
	long long target = 1;
	long long divide1, divide2;
	
	if(n == 1)
	{
		return a % c;
	}
	else
	{
	
		if(n%2 == 0)
		{
			divide1 = n/2;
			divide2 = n/2;
			target = solve(divide1);
			return (target * target) % c;
		}
		else
		{
			divide1 = n/2;
			divide2 = n/2+1;
			target = solve(divide1) * solve(divide2);

		}
		
		return target % c;
	}

}

int main()
{
	cin >> a >> b >> c;
	cout << solve(b);
}