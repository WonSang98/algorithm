#include <iostream>
using namespace std;

int n;
int A[1000];
int inc_arr[1000];
int dec_arr[1000];
int len = 0;
int max(int a, int b){
	return a > b ? a : b;
}

void init(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
}

void solve(){
	for(int i=0; i<n; i++){
		inc_arr[i] = 1;
		dec_arr[i] = 1;
		for(int j=0; j<i; j++){
			if(A[i] > A[j]){
				inc_arr[i] = max(inc_arr[i], inc_arr[j] + 1);
			}
			if(A[i] < A[j]){
				dec_arr[i] = max(inc_arr[j] + 1, dec_arr[i]);
				dec_arr[i] = max(dec_arr[i], dec_arr[j] + 1);
			}
		}
		len = max(inc_arr[i], len);
		len = max(dec_arr[i], len);
	}
	cout << len;
}
int main() {
	init();
	solve();
	return 0;
}
