#include <iostream>
#include <vector>
using namespace std;

bool arr[9] = {0,};
vector<int> v;

void solve(int num, int cnt, int n, int m)
{
	if(cnt == m+1)
	{
		for(int i=0; i<v.size(); i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for(int i=num; i<=n; i++)
		{
			if(arr[i] == false)
			{
				v.push_back(i);
				arr[i] = true;
				solve(i + 1, cnt + 1, n, m);
				v.pop_back();
				arr[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	solve(1, 1, n, m);
	
}