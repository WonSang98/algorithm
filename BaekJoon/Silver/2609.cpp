#include <iostream>
using namespace std;

//최대공약수
int GCD(int n, int m){
	if(n % m == 0) return m;
	return GCD(m, n % m);}

int main() {
	int n, m; cin >> n >> m;
	cout << GCD(n, m) << endl << n * m / GCD(n, m);
}
