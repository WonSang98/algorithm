#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int h[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++)
	{
		cin >> h[i];
	}
	
	sort(h, h+n);
	
	long long start = 0, end = h[n-1];
	long long cut = (start + end) / 2;
	long long before = 0;
	long long wood = 0;
	
	while(before != cut)
	{
		wood = 0;
		for(int i=0; i<n; i++)
		{
			wood += h[i] - cut > 0 ? h[i] - cut : 0;
		}
		
		if(wood < m) // cut을 낮춰야함
		{
			end = cut - 1;
		}
		else //cut 높여야함
		{
			start = cut + 1;
		}
		before = cut;
		cut = (start + end) / 2;
	}
	cout << cut;
	
	
}