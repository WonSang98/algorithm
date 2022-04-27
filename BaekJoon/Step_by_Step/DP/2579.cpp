#include <iostream>
using namespace std;

int find_max(int a, int b, int c)
{
	int max = a;
	max = max > b ? max : b;
	max = max > c ? max : c;
	
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	/*
	XX0
	X00
	*/
	
	int n;
	int stair[301];
	int dp[301];
	
	int up[2]; //0 XX0 , 1 X00
	cin >> n;
	
	cin >> stair[1];
	dp[1] = stair[1];
	
	dp[0] = 0;
	stair[0] = 0;
	
	for(int i=2; i<=n; i++)
	{
		cin >> stair[i];
		if(i == 2)
		{
			dp[2] = dp[1] + stair[2];
		}
		else if(i == 3)
		{
			dp[3] = stair[1] + stair[3] > stair[2] + stair[3] ? stair[1] + stair[3] : stair[2] + stair[3];
		}
		else
		{
			up[0] = dp[i - 2] + stair[i];
			up[1] = dp[i - 3] + stair[i-1] + stair[i];
			
			dp[i] = up[0] > up[1] ? up[0] : up[1];
		}
	}
	
	cout << dp[n];
	
	
}