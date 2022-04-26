#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	deque<int> dq;
	bool isRight = 1;
	bool isfail = 0;
	
	int t;
	cin >> t;
	
	string fu;
	
	int numArr;
	string strArr;
	
	for(int i=0; i<t; i++)
	{
		isRight = 1;
		isfail = 0;
		cin >> fu >> numArr >> strArr;
		
		int num = 0;
		for(int j=0; j<strArr.size(); j++)
		{
			if(strArr[j] == ']' || strArr[j] == ',')
			{
				if(num != 0) dq.push_back(num);
				num = 0;
			}
			else if(strArr[j] >= '0' && strArr[j] <='9')
			{
				num *= 10;
				num += (int)(strArr[j] - '0');
			}
		}
		
		for(int k=0; k<fu.size(); k++)
		{
			if(fu[k] == 'R')
			{
				isRight = isRight ? 0 : 1;
			}
			else if(fu[k] == 'D')
			{
				if(dq.size() >= 1)
				{
					if(isRight)
					{
						dq.pop_front();
					}
					else
					{
						dq.pop_back();
					}
				}
				else
				{
					cout << "error" << '\n';
					isfail = 1;
					break;
				}
			}
		}
		
		if(isfail)
		{
			continue;
			while(dq.empty() == false) dq.pop_back();
		}
		else
		{
			cout << '[';
			while(dq.empty() == false)
			{
				if(isRight)
				{
					cout << dq.front();
					dq.pop_front();
				}
				else
				{
					cout << dq.back();
					dq.pop_back();
				}
				if(!dq.empty()) cout << ',';
				
			}
			cout << ']' << '\n';
		}
	}
}