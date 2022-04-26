#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<pair<int, int>> q; //단순히 큐 저장
	priority_queue<int> pq; //중요도 저장
	
	int t, n, m;
	cin >> t;
	
	for(int i=0; i<t; i++)
	{
		cin >> n >> m;
		for(int j=0; j<n; j++)
		{
			int _value;
			cin >> _value;
			q.push(pair<int, int>(j, _value));
			pq.push(_value);
		}
		
		int cnt = 1;
		
		while(q.empty() == false)
		{
			
			while(q.front().second != pq.top())
			{
				q.push(pair<int, int>(q.front().first, q.front().second));
				q.pop();
			}
			
			if(q.front().first == m)
			{
				cout << cnt << '\n';
			}
			
			cnt++;
			q.pop();
			pq.pop();
		}
		
		
		
	}
	
	
}