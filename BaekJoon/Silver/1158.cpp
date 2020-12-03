#include <iostream>
using namespace std;

bool check[5001] = {0, };
int n, k;

void solve(int idx, int cnt){
	if(cnt == n){
		cout << idx << ">" << endl;
		return;}
	else {
		cout << idx << ", ";
		check[idx] = 1;
	}
	int cycle = 0;
	
	while(cycle != k){
		if(++idx == (n + 1)) idx = 1;
		if(check[idx] == true) continue;
		else cycle++;
	}
	
	solve(idx, cnt+1);
}

int main() {
	cin >> n >> k;
	cout << "<";
	solve(k, 1);
	return 0;
}
