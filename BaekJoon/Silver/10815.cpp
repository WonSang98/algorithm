#include <iostream>
#include <algorithm>
using namespace std;

int a[500000];
int b[500000];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	
	int m;
	cin >> m;
	for(int i=0; i<m; i++) cin >> b[i];
	
	sort(a, a+n);
	
	int start = 0, end = n;
	int mid = (start + end ) / 2;
	bool isfind = 0;
	
	for(int i=0; i<m; i++)
	{
		start = 0, end = n;
		mid = (start + end) / 2;
		isfind = 0;
		while(start <= end)
		{
			if(b[i] == a[mid])
			{
				isfind = 1;
				break;
			}
			if(b[i] > a[mid])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
			mid = (start + end)/2;
		}
		cout << isfind << ' ';
	}
	
	
	
}