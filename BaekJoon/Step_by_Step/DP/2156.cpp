#include <iostream>
using namespace std;

int n;
int wine[10001];
int dp[10001];

int max(int a, int b){
	return a > b ? a : b;
}

void init(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> wine[i];
	}
}

void solve(){
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	dp[3] = max(max(dp[1] + wine[3], dp[1] + wine[2]), wine[2] + wine[3]);
	for(int i = 4; i <= n; i++){
        int n1 = dp[i-1];
        int n2 = dp[i-2] + wine[i];
        int n3 = dp[i-3] + wine[i] + wine[i-1];
        dp[i] = max(max(n1, n2), n3);
	}
	cout << dp[n];
}
int main() {
	init();
	solve();
	// your code goes here
	return 0;
}
