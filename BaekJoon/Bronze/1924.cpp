#include <iostream>
using namespace std;

int main() {
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int x, y;
	cin >> x >> y;
	for(int i=1; i<x; i++) y += months[i];
	cout << days[y % 7];
}
