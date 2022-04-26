#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long dp[101];
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	
	int t, n;
	cin >> t;
	
	for(int i=4; i<=100; i++)
	{
		dp[i] = dp[i-2] + dp[i-3];
	}
	
	for(int i=0; i<t; i++)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}