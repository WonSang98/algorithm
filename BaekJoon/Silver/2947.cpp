#include <iostream>
using namespace std;

int woods[5];

void show()
{
	for(int i=0; i<5; i++) cout << woods[i] << ' ';
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<5; i++) cin >> woods[i];
	
	//bubble
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<4-i; j++)
		{
			if(woods[j] > woods[j+1])
			{
				int tmp = woods[j];
				woods[j] = woods[j+1];
				woods[j+1] = tmp;
				show();
			}
		}
	}
	
}