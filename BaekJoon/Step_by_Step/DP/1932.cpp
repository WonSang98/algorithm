#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int num;
	int dp[501];
	int pre_dp[501];
	for(int i=0; i<502; i++)
	{
		dp[i] = 0;
		pre_dp[i] = 0;
	}
	cin >> n;
	
	cin >> dp[1];
	pre_dp[1] = dp[1];
	
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			cin >> num;
			pre_dp[j] = dp[j-1] + num > dp[j] + num ? dp[j-1] + num : dp[j] + num;
		}
		for(int k=1; k<=i; k++)
		{
			dp[k] = pre_dp[k];
		}
	}
	int answer = 0;
	for(int i=0; i<=n; i++)
	{
		answer = answer < dp[i] ? dp[i] : answer;
	}
	cout << answer;
}