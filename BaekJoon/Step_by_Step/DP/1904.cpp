#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int dp[1000001];
	dp[0] = 0;
	dp[1] = 1; // 1
	dp[2] = 2; // 00, 11;
	
	for(int i=3; i<=n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746; 
	}
	
	cout << dp[n];
}