#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int dp[3];
	int temp[3];
	int cost[3]; 
	
	int t;
	cin >> t;
	cin >> dp[0] >> dp[1] >> dp[2];
	
	for(int i=1; i<t; i++)
	{
		
		cin >> cost[0] >> cost[1] >> cost[2];
		
		temp[0] = cost[0] + dp[1] < cost[0] + dp[2] ? cost[0] + dp[1] : cost[0] + dp[2];
		temp[1] = cost[1] + dp[0] < cost[1] + dp[2] ? cost[1] + dp[0] : cost[1] + dp[2];
		temp[2] = cost[2] + dp[0] < cost[2] + dp[1] ? cost[2] + dp[0] : cost[2] + dp[1];
		
		dp[0] = temp[0];
		dp[1] = temp[1];
		dp[2] = temp[2];
		
	}
	
	int answer;
	answer = dp[0] < dp[1] ? dp[0] : dp[1];
	answer = answer < dp[2] ? answer : dp[2];
	
	cout << answer;
	
}