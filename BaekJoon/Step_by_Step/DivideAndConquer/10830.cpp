#include <iostream>
#include <vector>
using namespace std;

vector<long long> mat;
vector<long long> tmp;
vector<long long> tmp2;
long long n, _exp;

void init()
{
	long long tmp;
	for(int y=0; y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			cin >> tmp;
			mat.push_back(tmp%1000);
		}
	}
}

vector<long long> mul(vector<long long> a, vector<long long> b)
{
	tmp.clear();
	long long elm;
	for(int y=0; y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			elm = 0;
			for(int i=0; i<n; i++)
			{
				elm += a[(y * n) + i] * b[(i * n) + x];
				elm %= 1000;
			}
			tmp.push_back(elm);
		}
	}
	return tmp;
}

vector<long long> solve(long long b)
{
	if(b == 1)
	{
		return mat;
	}
	else
	{
		tmp2.clear();
		if(b % 2)
		{
			tmp2 = solve(b-1); 
			return mul(tmp2, mat);
		}
		else
		{
			tmp2 = solve(b/2);
			return mul(tmp2, tmp2); 
		}
	}
}



int main()
{
	cin >> n >> _exp;
	init();
	
	vector<long long> answer = solve(_exp);
	for(int y=0; y<n; y++)
	{
		for(int x=0; x<n; x++)
		{
			cout << answer[(y*n)+x] << ' ';
		}
		cout << '\n';
	}
}