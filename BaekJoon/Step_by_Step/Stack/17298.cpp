#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, tmp;
	cin >> n;
	
	stack<int> ori;
	stack<int> drop;
	stack<int> answer;
	
	for(int i=0; i<n; i++)
	{
		cin >> tmp;	
		ori.push(tmp);
	}
	
	drop.push(ori.top());
	answer.push(-1);
	ori.pop();
	for(int i=1; i<n; i++)
	{
		while(!drop.empty())
		{
			if(drop.top() > ori.top())
			{
				answer.push(drop.top());
				drop.push(ori.top());
				ori.pop();
				break;
			}
			else
			{
				drop.pop();
			}
		}
		
		if(drop.empty())
		{
			answer.push(-1);
			drop.push(ori.top());
			ori.pop();
		}
	}
	
	
	while(!answer.empty())
	{
		tmp= answer.top();
		cout << tmp << ' ';
		answer.pop();
	}
	
}
