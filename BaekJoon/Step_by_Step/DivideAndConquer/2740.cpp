#include <iostream>
using namespace std;

int arr1[101][101];
int arr2[101][101];
int answer[101][101];

int main()
{
	int n1, m1;
	int n2, m2;
	cin >> n1 >> m1;
	
	for(int y=0; y<n1; y++)
	{
		for(int x=0; x<m1; x++)
		{
			cin >> arr1[y][x];
		}
	}
	
	cin >> n2 >> m2;
	for(int y=0; y<n2; y++)
	{
		for(int x=0; x<m2; x++)
		{
			cin >> arr2[y][x];
		}
	}
	
	for(int y=0; y<n1; y++)
	{
		for(int x=0; x<m2; x++)
		{
			answer[y][x] = 0;
			for(int i=0; i<m1; i++)
			{
				answer[y][x] += arr1[y][i] * arr2[i][x];
			}
			cout << answer[y][x] << ' ';
		}
		cout << '\n';
	}
	
	
}