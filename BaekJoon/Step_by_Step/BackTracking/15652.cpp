#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

void solve(int cnt, int num)
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
			v.push_back(i);
			solve(cnt + 1, i);
			v.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	
	solve(1, 1);
}