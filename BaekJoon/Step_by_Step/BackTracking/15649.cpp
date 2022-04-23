#include <iostream>
#include <vector>
using namespace std;

bool arr[9] = {0,};
vector<int> v;

void combine(int cnt, int n, int m)
{
	if(cnt == m + 1)
	{
		for(int i=0; i<v.size(); i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			if(arr[i] == false)
			{
				v.push_back(i);
				arr[i] = true;
				combine(cnt + 1, n, m);
				if(v.size() > 0) v.pop_back();
				arr[i] = false;
			}
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	combine(1, n, m);
	
	
}