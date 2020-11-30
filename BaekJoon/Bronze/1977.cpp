#include <iostream>
using namespace std;

bool judge_ps(int n){
	for(int i=1; i<=100; i++){
		if(i*i == n) return 1;}
	return 0;
}

int main() {
	int n, m, i;
	int sum = 0;
	int min_num = 10001;
	
	cin >> n >> m;
	for(int i=n; i<=m; i++){
		if(judge_ps(i)){
			sum += i;
			min_num = i < min_num ? i : min_num;
		}
	}
	if(sum == 0) cout << -1;
	else cout << sum << endl << min_num << endl;
}
