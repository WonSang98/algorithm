#include <iostream>
#include <deque>
using namespace std;

int main()
{
	deque<int> dq;
	int n, _input;
	cin >> n;
	string ins;
	
	for(int i=0; i<n; i++)
	{
		cin >> ins;
		
		if(ins == "push_front")
		{
			cin >> _input;
			dq.push_front(_input);
		}
		else if(ins == "push_back")
		{
			cin >> _input;
			dq.push_back(_input);			
		}
		else if(ins == "pop_front")
		{
			if(dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			
		}
		else if(ins == "pop_back")
		{
			if(dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if(ins == "size")
		{
			cout << dq.size() << '\n';
		}
		else if(ins == "empty")
		{
			if(dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(ins == "front")
		{
			if(dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else if(ins == "back")
		{
			if(dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}
}