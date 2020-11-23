#include <iostream>
using namespace std;

int n;
int answer = 0;
int stair[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int dp[10];

void solve(){
	for(int i=2; i<=n; i++){
		for(int j=0; j<10; j++){
			if(j == 0) dp[0] = stair[1];
			else if(j == 9) dp[9] = stair[8];
			else dp[j] = stair[j-1] + stair[j+1];
			dp[j] %= 1000000000;
		}
		for(int k=0; k<10; k++){
			stair[k] = dp[k];
		}
	}
	for(int j=0; j<10; j++){
		answer += stair[j];
		answer %= 1000000000;
	}
	cout << answer;
}

int main() {
	cin >> n;
	solve();
	return 0;
}
