#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int move(string& s, int& pointer){
  int c=pointer;
  while(pointer<s.size() && s[pointer]==s[c]){
    pointer++;
  }
  return pointer-c;
}

void solve(){
  cin>>N;
  vector<string> s(N);
  vector<int> p(N,0);
  vector<int> siz(N);
  for(int i=0;i<N;i++)
    cin>>s[i];
  int count = 0;
  while(p[0]<s[0].size()){
    char c = s[0][p[0]];
    for(int i=1;i<N;i++)
      if(p[i]>=s[i].size() || s[i][p[i]]!=c){
	cout<<"Fegla Won";
	return;
      }
    for(int i=0;i<N;i++){
      siz[i] = move(s[i],p[i]);
    }
    sort(siz.begin(),siz.end());
    int target = siz[N/2];
    for(int el:siz)
      count += abs(el-target);    
  }
  for(int i=1;i<N;i++)
    if(p[i]!=s[i].size()){
	cout<<"Fegla Won";
	return;
    }
  cout<<count;
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
    cout<<endl;
  }
}
