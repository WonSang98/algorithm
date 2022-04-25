#include <iostream>
#include <vector>
using namespace std;

int arr[21][21];
int n;
int min_sub = 210000000;
vector<int> line_start;
vector<int> line_link;

void set_link()
{
	line_link.clear();
	bool check[21] = {0, };
	for(int i=0; i<line_start.size(); i++)
	{
		check[line_start[i]] = true;
	}
	for(int i=1; i<=n; i++)
	{
		if(check[i] == false)
		{
			line_link.push_back(i);
		}
	}
}

int cal()
{
	int score_start = 0;
	int score_link = 0;
	//team_start
	for(int i=0; i<line_start.size(); i++)
	{
		for(int j=0; j<line_start.size(); j++)
		{
			if(j == i) continue;
			score_start += arr[line_start[i]][line_start[j]];
		}
	}
	
	//team_link
	for(int i=0; i<line_link.size(); i++)
	{
		for(int j=0; j<line_link.size(); j++)
		{
			if(j == i) continue;
			score_link += arr[line_link[i]][line_link[j]];
		}
	}
	
	return score_start > score_link ? score_start - score_link : score_link - score_start;
}

void solve(int num, int cnt)
{
	if(cnt == n / 2)
	{
		set_link();
		int diff = cal();
		if(diff < min_sub)
		{
			min_sub = diff;
		}
		
	}
	else
	{
		for(int i=num; i<=n; i++)
		{
			line_start.push_back(i);
			solve(i+1, cnt+1);
			line_start.pop_back();
		}
		
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	solve(1, 0);
	cout << min_sub;
	
	
}