#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m, x, y, k;
int _map[20][20];
queue<int> _move;
map<string, int> dice = {{"top", 1}, {"right", 3}, {"left", 4}, {"front", 5}, {"back", 2}, {"bottom", 6}};
map<int, int> dice_val = {{1, 0}, {2, 0}, {3, 0}, {4,0}, {5,0}, {6,0}};


void init()
{
	for(int posX = 0; posX < n; posX++)
	{
		for(int posY = 0; posY <m; posY++)
		{
			cin >> _map[posX][posY];
		}
	}
	
	int tmp;
	for(int i=0; i<k; i++)
	{
		cin >> tmp;
		_move.push(tmp);
	}
}

void rollDice(int m)
{
	int tmp;
	switch(m)
	{
		case 1: // 동 : top -> right , right -> bottom , bottom -> left , left -> top
			tmp = dice["top"];
			dice["top"] = dice["left"];
			dice["left"] = dice["bottom"];
			dice["bottom"] = dice["right"];
			dice["right"] = tmp;
			break;
		case 2: // 서 top -> left, left -> bottom, bottom -> right , right -> top
			tmp = dice["top"];
			dice["top"] = dice["right"];
			dice["right"] = dice["bottom"];
			dice["bottom"] = dice["left"];
			dice["left"] = tmp;
			break;
		case 3: // 북 top -> back, back -> bottom , bottom ->front, front -> top
			tmp = dice["top"];
			dice["top"] = dice["front"];
			dice["front"] = dice["bottom"];
			dice["bottom"] = dice["back"];
			dice["back"] = tmp;
			break;
		case 4: // 남 top -> front, front -> bottom, botton -> back, back -> top
			tmp = dice["top"];
			dice["top"] = dice["back"];
			dice["back"] = dice["bottom"];
			dice["bottom"] = dice["front"];
			dice["front"] = tmp;
			break;
	}
	
}

void solve()
{
	int go;
	while(_move.empty() == false)
	{
		go = _move.front();
		_move.pop();
		switch(go)
		{
			case 1: //동
				if(y+1 >= m) continue;
				else y += 1;
				break;
			case 2: //서
				if(y-1 < 0) continue;
				else y -= 1;
				break;
			case 3: //북
				if(x-1 < 0) continue;
				else x -= 1;
				break;
			case 4: //남
				if(x+1 >= n) continue;
				else x += 1;
				break;
		}
		rollDice(go);
		if(_map[x][y] == 0)
		{
			_map[x][y] = dice_val[dice["bottom"]];
		}
		else
		{
			dice_val[dice["bottom"]] = _map[x][y];
			_map[x][y] = 0;
		}
		cout << dice_val[dice["top"]] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x >> y >> k;
	init();
	solve();
}