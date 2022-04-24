#include <iostream>
using namespace std;

int arr[15];
int n;
int answer;

bool check(int i, int cnt)
{
	for(int j=0; j<cnt; j++)
	{
		if( i == arr[j]) return false;
		if( i == (arr[j] + (cnt - j))) return false;
		if( i == (arr[j] - (cnt - j))) return false;
	}
	
	return true;
}

void solve(int cnt)
{
	if(cnt == n)
	{
		answer += 1;
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			if(check(i, cnt))
			{
				arr[cnt] = i;
				solve(cnt + 1);
			}
		}
		
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	answer = 0;
	
	cin >> n;
	
	solve(0);
	cout << answer;
}