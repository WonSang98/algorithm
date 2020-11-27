#include <iostream>
using namespace std;

int line[501] = {0, };
int dp[501] = {0, };
int n;
int min_idx = 1000;
int max_idx = -1000;
void init(){
  cin >> n;
  int idx;
  for(int i=0; i<n; i++){
    cin >> idx;
    min_idx = idx < min_idx ? idx : min_idx;
    max_idx = idx > max_idx ? idx : max_idx;
    cin >> line[idx];
  }
}

void solve(){
  int max_num = 0;
  for(int i=min_idx; i<=max_idx; i++){
    if(line[i] == 0) dp[i] = 0;
    else dp[i] = 1;
    for(int j=min_idx; j<i; j++){
      if(line[i] > line[j]){
        dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;}
      }
      max_num = dp[i] > max_num ? dp[i] : max_num;
    }
    cout << (n - max_num);
}

int main(){
  init();
  solve();
}
