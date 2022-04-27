#include <iostream>
using namespace std;

int paper[128][128];
int blue = 0;
int white = 0;

void init(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> paper[i][j];
		}
	}
}

void dc(int posY, int posX, int size)
{
	bool check = 1;
	bool color = paper[posY][posX];
	for(int y = posY; y < posY + size; y++)
	{
		for(int x = posX; x < posX + size; x++)
		{
			if(color != paper[y][x])
			{
				check = 0;
				break;
			}
			color = paper[y][x];
		}
		if(check == 0) {break;}
	}
	
	if(check == 0)
	{
		dc(posY, posX, size / 2);
		dc(posY + size / 2, posX, size / 2);
		dc(posY, posX + size / 2, size / 2);
		dc(posY + size / 2, posX + size / 2, size / 2);	
	}
	else
	{
		if(color == 1)
		{
			blue += 1;
		}	
		else
		{
			white += 1;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	init(n);
	
	dc(0, 0, n);
	cout << white << '\n' << blue;
}