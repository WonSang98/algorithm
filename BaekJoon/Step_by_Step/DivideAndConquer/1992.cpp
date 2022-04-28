#include <iostream>
using namespace std;

bool arr[64][64];
string answer;

void init(int n)
{
	string tmp;
	for(int i=0; i<n; i++)
	{
		cin >> tmp;
		for(int j=0; j<n; j++)
		{
			arr[i][j] = (tmp[j] == '1') ? 1 : 0;
		}
	}
}

void solve(int posY, int posX, int size)
{
	bool check = 1;
	bool bw = arr[posY][posX];
	for(int y = posY; y < posY + size; y++)
	{
		for(int x = posX; x < posX + size; x++)
		{
			if(arr[y][x] != bw)
			{
				check = 0;
				break;
			}
			bw = arr[y][x];
		}
		if(check == 0) break;
	}
	
	if(check == 0)
	{
		cout << '(';
		solve(posY, posX, size / 2);
		solve(posY, posX + size / 2, size / 2);
		solve(posY + size/2, posX, size / 2);
		solve(posY + size/2, posX + size/2 , size / 2);
		cout << ')';
	}
	else
	{
		cout << bw;
	}
	
}


int main()
{
	int n;
	cin >> n;
	init(n);
	solve(0, 0, n);
}