#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k; // 갖고 있는 랜선의 개수 (1 <= k <= 10000)
	int n; // 만들어야 할 랜선의 개수(1 <= n <= 10000000)
	cin >> k >> n;
	
	int lanlines[10000] = {0,};
	int cut[10000] = {0,}; // 자를 길이
	
	for(int i=0; i<k; i++)
	{
		cin >> lanlines[i];
		cut[i] = lanlines[i];
	}
	
	sort(lanlines, lanlines + k, cmp);
	
	long start = 1, end = lanlines[0];
	long target = (start + end) / 2;
	long before_len = 0;
	long cnt = 0;
	
	while(before_len != target)
	{
		cnt = 0;
		for(int i=0; i<k; i++)
		{
			cnt += lanlines[i] / target;
		}
		if(cnt < n) //더 많이 잘라야 하니 작게
		{
			end = target - 1;
		}
		else // 더 적게 잘라야 하니 크게
		{
			start = target + 1;
		}
		before_len = target;
		target = (start + end) / 2;
	}
	cout << target;
}
