#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> cnt_num;

void solve()
{	
	cnt_num.push_back(pair<int, int>(1, 0));
	cnt_num.push_back(pair<int, int>(0, 1));
	
	for(int i=2; i<=40; i++)
	{
		cnt_num.push_back(pair<int, int>(cnt_num[i-1].first + cnt_num[i-2].first, cnt_num[i-1].second + cnt_num[i-2].second ));
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	int t, n;
	
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		cin >> n;
		cout << cnt_num[n].first << ' ' << cnt_num[n].second << '\n';
	}
}