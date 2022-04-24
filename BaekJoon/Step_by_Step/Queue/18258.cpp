#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	queue<int> q;
	int n,tmp;
	string ins;
	
	cin >> n;
	
	for(int i=0; i<n; i++)
	{
		cin >> ins;
		if(ins == "push")
		{
			cin >> tmp;
			q.push(tmp);
		}
		else if(ins == "pop")
		{
			if(q.empty()) cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if(ins == "size")
		{
			cout << q.size() << '\n';
		}
		else if(ins == "empty")
		{
			if(q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(ins == "front")
		{
			if(q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if(ins == "back")
		{
			if(q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
	
	
	
	
}