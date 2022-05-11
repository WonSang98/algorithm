#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	
	return a.first > b.first;
}

bool _order(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	int tmp;
	vector<pair<int, int>> v;
	for(int i=0; i<8; i++)
	{
		cin >> tmp;
		v.push_back(pair<int, int>(tmp, i+1));
	}
	
	sort(v.begin(), v.end(), cmp);
	sort(v.begin(), v.begin() + 5, _order);

	int sum = 0;
	for(int i=0; i<5; i++)
	{
		sum += v[i].first;
	}
	cout << sum << '\n';
	
	for(int i=0; i<5; i++)
	{
		cout << v[i].second << ' ';
	}
}
