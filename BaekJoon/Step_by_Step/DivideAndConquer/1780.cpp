#include <iostream>
using namespace std;

int arr[2188][2188];
int answer[3] = {0, 0, 0};

void init(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void solve(int posY, int posX, int size)
{
	bool check = 1;
	int num = arr[posY][posX];
	
	for(int y = posY; y < posY + size; y++)
	{
		for(int x = posX; x < posX + size; x++)
		{
			if(num != arr[y][x])
			{
				check = 0;
				break;
			}
			num = arr[y][x];
		}
		if(check == 0){break;}
	}
	
	if(check == 0)
	{
		int jump = size / 3;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				solve(posY + (i * jump), posX + (j * jump), jump);
			}
		}
	}
	else
	{
		if(num == -1) answer[0] += 1;
		else if(num == 0) answer[1] += 1;
		else if(num == 1) answer[2] += 1;
	}
}



int main()
{
	int n;
	cin >> n;
	init(n);
	solve(0, 0, n);
	cout << answer[0] << '\n' << answer[1] << '\n' << answer[2];
}