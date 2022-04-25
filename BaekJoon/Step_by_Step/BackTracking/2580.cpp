#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
vector<pair<int, int>> pos;
int cnt;

void setting()
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			arr[i][j] = 0;
		}
	}
}

bool check(int _cnt, int num)
{
	for(int i=0; i<9; i++)
	{
		if(num == arr[pos[_cnt].first][i]) return false;
	}
	for(int i=0; i<9; i++)
	{
		if(num == arr[i][pos[_cnt].second]) return false;
	}
		
	int y = 3 * (pos[_cnt].first / 3);
	int x = 3 * (pos[_cnt].second / 3);
	for(int i = y; i < y + 3; i++)
	{
		for(int j= x; j < x + 3; j++)
		{
			if(arr[i][j] == num) return false;
		}
	}
	
	return true;
}

void solve(int _cnt)
{
	if(_cnt == pos.size())
	{
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	else
	{
		for(int i=1; i<10; i++)
		{
			if(check(_cnt, i) == false) continue;
			arr[pos[_cnt].first][pos[_cnt].second] = i;
			solve(_cnt + 1);
			arr[pos[_cnt].first][pos[_cnt].second] = 0;
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	setting();
	cnt = 0;
	
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 0)
			{
				pos.push_back(pair<int, int>(i, j));
			}
		}
	}
	solve(0);
}