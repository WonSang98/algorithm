#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 9;
	for(int i=1; i<n; i++){
		answer *= 2;
		answer -= i;
		answer %= 1000000000;
	}
	cout << answer;
	return 0;
}
