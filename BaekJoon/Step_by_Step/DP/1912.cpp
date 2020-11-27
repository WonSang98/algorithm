#include <iostream>
using namespace std;

int n;
int arr[100000];
int dp[100000];

void init(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
}

void solve(){
	dp[0] = arr[0];
	int max_num = dp[0];
	for(int i=1; i<n; i++){
		dp[i] = dp[i-1] + arr[i] > arr[i] ? dp[i-1] + arr[i] : arr[i];
		max_num = dp[i] > max_num ? dp[i] : max_num;
	}
	cout << max_num;
}
int main() {
	init();
	solve();
}
