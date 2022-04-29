#include <iostream>
#include <vector>
using namespace std;

unsigned long long p = 1000000007;
vector<unsigned long long> default_mat = {1, 1, 1, 0};
vector<unsigned long long> tmp;
vector<unsigned long long> tmp2;
unsigned long long n;

vector<unsigned long long> mul(vector<unsigned long long> a, vector<unsigned long long> b)
{
	unsigned long long elm;
	tmp.clear();
	for(int y=0; y<2; y++)
	{
		for(int x=0; x<2; x++)
		{
			elm = 0;
			for(int i=0; i<2; i++)
			{
				elm += a[(y*2) + i] * b[(i * 2) + x];
				elm %= p;	
			}
			tmp.push_back(elm);
		}
	}
	return tmp;
}


vector<unsigned long long> solve(unsigned long long _exp)
{
	if(_exp == 1)
	{
		return default_mat;
	}
	else
	{
		tmp2.clear();
		if(_exp % 2)
		{
			tmp2 = solve(_exp -1);
			return mul(tmp2, default_mat);
		}
		else
		{
			tmp2 = solve(_exp / 2);
			return mul(tmp2, tmp2);
		}
	}
}

int main()
{
	cin >> n;
	
	tmp = solve(n);
	cout << (tmp[2]) % p;
}