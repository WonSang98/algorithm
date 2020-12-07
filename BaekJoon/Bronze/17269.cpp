#include <iostream>
#include <vector>
using namespace std;

int alp[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int len1, len2;
string name1, name2;
vector <int> v;

void init(){
	cin >> len1 >> len2;
	cin >> name1 >> name2;
	int max_len = len1 > len2 ? len1 : len2;
	for(int i=0; i<max_len; i++){
		if(len1 > i) v.push_back(alp[int(name1[i])-65]);
		if(len2 > i) v.push_back(alp[int(name2[i])-65]);
	}
}

void test(vector<int> v){
	if(v.size() == 2){
		int score = 10 * v[0] + v[1];
		cout << score << "%";
		return;}
	vector <int> v2;
	for(int i=1; i<v.size(); i++){
		v2.push_back((v[i] + v[i-1])%10);
	}
	test(v2);
}
int main() {
	init();
	test(v);
}
