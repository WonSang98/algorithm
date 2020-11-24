#include <iostream>
using namespace std;

int n;
int arr[1000];
int dp[1000] = {1, };

int max_len = 1;

int max(int a, int b){
	return a > b ? a: b;
}

void init(){
	cin >> n;
	for(int i=0; i<1000; i++){
		cin >> arr[i];
	}
}

void solve(){
	dp[0] = 1;
	for(int i=1; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);
				max_len = max(max_len, dp[i]);
			}
		}
	}
	cout << max_len;
}


int main() {
	init();
	solve();
}
