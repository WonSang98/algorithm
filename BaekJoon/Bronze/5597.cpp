#include <iostream>
using namespace std;

int main() {
	bool check[31] = {0, };
	int temp;
	for(int i=0; i<28; i++){
		 cin >> temp;
		 check[temp] = 1;}
	for(int j=1; j<31; j++){
		if(check[j] == 0) cout << j << endl;
	}
}
