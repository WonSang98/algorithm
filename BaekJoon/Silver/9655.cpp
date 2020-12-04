#include <iostream>
using namespace std;

int n;
int dp[1000];

int min(int a, int b){
	return a < b ? a : b;
}

void solve(){
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 1;
	for(int i=3; i<n; i++){
		dp[i] = min(dp[i-3] + 1, dp[i-1] + 1);
	}
	if(dp[n-1] % 2) cout << "SK";
	else cout << "CY";
}
int main() {
	cin >> n;
	solve();
	return 0;
}
