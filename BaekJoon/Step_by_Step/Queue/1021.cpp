#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;
	int n, m, findNum;
	int cnt = 0, mid = 0, l = 0;
	cin >> n >> m;
	for(int i=1; i<=n; i++){dq.push_back(i);}
	
	for(int i=0; i<m; i++)
	{
		cin >> findNum;
		l = (dq.size() / 2);
		mid = dq[l];
		
		int idx = -1;
		
		for(int j=0; j<=l; j++)
		{
			if(dq[j] == findNum) idx = j;
		}

		while(dq.front() != findNum)
		{
			if(idx != -1)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			} 
			
		}
		dq.pop_front();
		
	}
	cout << cnt; 
	
	
}

