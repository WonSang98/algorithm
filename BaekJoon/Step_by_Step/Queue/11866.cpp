#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	vector<int> answer;
	int n, k;
	cin >> n >> k;
	
	for(int i=1; i<=n; i++) q.push(i);
	
	while(q.empty() == false)
	{
		for(int i=1; i<k; i++)
		{
			q.push(q.front());
			q.pop();
		}
		answer.push_back(q.front());
		q.pop();
	}
	
	cout << "<" << answer[0];
	for(int i=1; i<answer.size(); i++)
	{	
		cout << ", ";
		cout << answer[i];
	}
	cout << ">";
	
	
	
}