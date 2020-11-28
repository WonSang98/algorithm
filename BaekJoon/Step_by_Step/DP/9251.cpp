#include <iostream>
using namespace std;

string a, b, temp;
int dp[1001][1001] = {0, };

void init(){
	cin >> a >> b;
	if(a.length() > b.length()){
		temp = a;
		a = b;
		b = temp;
	}
}

int max(int a, int b){
	return a > b ? a : b;
}

void solve(){
	for(int i=1; i<=a.length(); i++){
		for(int j=1; j<=b.length(); j++){
			if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+1);
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	cout << dp[a.length()][b.length()];
}


int main(){
	init();
	solve();
}
