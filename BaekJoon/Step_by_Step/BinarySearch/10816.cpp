#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	map<int, int> _inputData;
	
	int n;
	cin >> n;
	int num;
	
	for(int i=0; i<n; i++)
	{
		cin >> num;
		auto iter = _inputData.find(num);
		if(iter == _inputData.end())
		{
			_inputData.insert({num, 1});
		}
		else
		{
			iter->second += 1;
		}
	}
	
	int m;
	cin >> m;
	
	for(int i=0; i<m; i++)
	{
		cin >> num;
		auto iter = _inputData.find(num);
		if(iter == _inputData.end())
		{
			printf("0 ");
		}
		else
		{
			printf("%d ", iter->second);
		}
	}
	
}