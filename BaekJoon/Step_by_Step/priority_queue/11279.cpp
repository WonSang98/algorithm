#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<int> pq;
	
	int n;
	cin >> n;
	
	int _input;
	for(int i=0; i<n; i++)
	{
		cin >> _input;
		if(_input == 0)
		{
			if(pq.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(_input);
		}
	}
}