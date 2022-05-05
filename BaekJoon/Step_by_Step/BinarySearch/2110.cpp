#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	int home[200000];
	
	for(int i=0; i<n; i++)
	{
		cin >> home[i];
	}
	
	sort(home, home+n);
	
	int start = 0, end = home[n - 1];
	int mid = (end + start) / 2 ;
	int cnt;
	int before;
	int prv;
	
	while(start <= end)
	{
		cnt = 1;
		prv = home[0];
		for(int i=1; i<n; i++)
		{
			if(home[i] - prv >= mid)
			{
				cnt += 1;
				prv = home[i];
			}
		}
		
		if(cnt >= m)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
		mid = (end + start) / 2;
	}
	
	cout << end;
	
	
}