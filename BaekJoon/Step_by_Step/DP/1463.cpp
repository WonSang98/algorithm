#include <iostream>
using namespace std;

int n;
int dp[1000001];
//각 숫자별 1이 될 때까지 수행해야하는 최소 단계 저장.

int min(int a, int b){
	return a < b ? a : b;
}

void solve(){
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	for(int i=4; i<=n; i++){
		if(i % 2 == 0 && i % 3 == 0){
			// i가 2의 배수이자 3의 배수인 경우
			dp[i] = min(min(dp[i / 2] + 1, dp[i / 3] + 1), dp[i - 1] + 1);
		}
		else if(i % 2 == 0){
			// i가 2의 배수인 경우
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		}
		else if(i % 3 == 0){
			// i가 3의 배수인 경우
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		}
		else{
			// i가 2의 배수도 3의 배수도 아닌 경우, (-1)
			dp[i] = dp[i-1] + 1;
		}
	}
	cout << dp[n];
}

int main() {
	cin >> n;
	solve();
	return 0;
}