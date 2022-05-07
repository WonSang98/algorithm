#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int a[50], b[50];
	
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	
	sort(a, a+n);
	sort(b, b+n, cmp);
	
	int answer = 0;
	
	for(int i=0; i<n; i++) answer += a[i] * b[i];
	
	cout << answer;
	
	
}