#include <iostream>
#include <time.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	int len = s.length();
	int f = 0, b = len-1;
	while(len >= 2){
		if(s[f] != s[b]) {
			cout << 0;
			return 0;}
		len -= 2;
		f += 1;
		b -= 1;
	}
	cout << 1;
	return 0;
}
