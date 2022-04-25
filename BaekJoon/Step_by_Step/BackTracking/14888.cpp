#include <iostream>
using namespace std;


int n;
int arr[11];
int oper[4];
int min_num = 2100000000;
int max_num = -2100000000;

void solve(int cnt, int result)
{
	if(cnt == n-1)
	{
		if(result > max_num) max_num = result;
		if(result < min_num) min_num = result;
	}
	else
	{
		for(int i=0; i<4; i++)
		{
			if(oper[i] <= 0) continue;
			else
			{
				oper[i] -= 1;
				
				switch(i)
				{
					case 0:
						solve(cnt + 1, result + arr[cnt + 1]);
						break;
					case 1:
						solve(cnt + 1, result - arr[cnt + 1]);
						break;
					case 2:
						solve(cnt + 1, result * arr[cnt + 1]);
						break;
					case 3:
						solve(cnt + 1, result / arr[cnt + 1]);
						break;
				}
				
				oper[i] += 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	for(int i=0; i<4; i++)
	{
		cin >> oper[i];
	}
	
	solve(0, arr[0]);
	
	cout << max_num << '\n' << min_num;
}