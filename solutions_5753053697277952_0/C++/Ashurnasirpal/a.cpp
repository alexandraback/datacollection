#include<bits/stdc++.h>
using namespace std;
typedef pair<int,char> P;

void solve(int num){
  int n,sum;
  priority_queue< P > que;
  cin >> n;
  for(int i = 0;i < n;++i){
    int p;
    cin >> p;
    sum += p;
    que.push(P(p,'A'+i));
  }
  cout << "Case #" << num << ":";
  while(!que.empty()){
    cout << " ";
    P next = que.top();
    que.pop();
    --next.first;--sum;
    cout << next.second;
    if(next.first != 0)que.push(next);
    if(sum % 2 == 0)continue;
    next = que.top();
    que.pop();
    --next.first;--sum;
    cout << next.second;
    if(next.first != 0)que.push(next);
  }
  cout << endl;
}

int main(void){
  int t;
  cin >> t;
  for(int i = 0;i < t;++i)solve(i+1);
  return 0;
}
