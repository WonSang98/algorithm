#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, find_num;
	int arr[100001];
	
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	cin >> m;
	
	int find_idx;
	int before_idx;
	int start_idx;
	int end_idx;
	int answer = 1;
	for(int i=0; i<m; i++)
	{
		cin >> find_num;
		start_idx = 0;
		end_idx = n-1;
		find_idx = (start_idx + end_idx) / 2;
		before_idx = -1;
		answer = 1;
		while(arr[find_idx] != find_num)
		{
			if(find_idx == before_idx)
			{
				answer = 0;
				break;
			}
			if(arr[find_idx] > find_num)
			{
				end_idx = find_idx-1;
			}
			else if(arr[find_idx] < find_num)
			{
				start_idx = find_idx+1;
			}
			before_idx = find_idx;
			find_idx = (start_idx + end_idx) / 2;
		}
		printf("%d\n", answer);
	}
	
}