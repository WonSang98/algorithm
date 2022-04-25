#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	queue<int> q;
	
	//init
	for(int i=1; i<=n; i++) q.push(i);
	
	while(q.size() > 1)
	{
		q.pop();
		if(q.size() == 1){break;}
		else{
			q.push(q.front());
			q.pop();
		}
	}
	
	cout << q.front();

}