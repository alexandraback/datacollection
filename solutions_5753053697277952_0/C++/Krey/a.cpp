#include<bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1100000;

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; tt++){
    int n;
    cin >> n;
    int suma = 0;
    int ile[30];
    for(int i = 0; i < n; i++){
      cin >> ile[i];
      suma+=ile[i];
    }
    priority_queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) q.push({ile[i],i});
    cout<<"Case #"<<tt<<": ";
    if(suma % 2 == 1){
      auto p = q.top();
      q.pop();
      char c = 'A' + p.sd;
      cout << c << " ";
      p.ft--;
      q.push(p);
      suma--;
    }
    for(int i = 0; i < suma / 2; i++){
      auto p1 = q.top();
      q.pop();
      auto p2 = q.top();
      q.pop();
      char c1 = 'A' + p1.sd, c2 = 'A' + p2.sd;
      cout << c1 << c2 << " ";
      p1.ft--;
      p2.ft--;
      q.push(p1);
      q.push(p2);
    }
    cout<<"\n";
  } 
}