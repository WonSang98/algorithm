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
	int answer = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	dp[3] = max(wine[2] + wine[3], dp[2]);
	for(int i = 4; i <= n; i++){
		dp[i] = max(dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i]);
		if(dp[i] > answer) answer = dp[i];
	}
	cout << answer;
}
int main() {
	init();
	solve();
	// your code goes here
	return 0;
}
