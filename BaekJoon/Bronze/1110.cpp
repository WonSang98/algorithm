#include <iostream>
using namespace std;

int main() {
	int n; // 주어진 수
	cin >> n;
	
	int left, right; // 왼쪽 수, 오른쪽 수
	int cycle = 0; // 사이클 수
	int num_new = n; // 계산된 수
	
	
	do{
		left = num_new / 10;
		right = num_new % 10;
		num_new = right * 10 + ((left + right) % 10);
		cycle += 1;
	}while(n != num_new);
	
	cout << cycle;
	
}
