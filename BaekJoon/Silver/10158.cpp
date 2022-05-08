#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int w, h;
	cin >> w >> h;
	
	int x, y;
	cin >> x >> y;
	
	int t;
	cin >> t;
	
	x = (x + t) % (w * 2);
	y = (y + t) % (h * 2);
	
	if(x > w) x = (w * 2) - x;
	if(y > h) y = (h * 2) - y;
		
	cout << x << ' ' << y;
}