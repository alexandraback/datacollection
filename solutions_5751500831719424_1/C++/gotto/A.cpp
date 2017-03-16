#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int T;
int N;
string s[111];
string ss[111];
vector<int> v[111];
int ch[111];
int main(void){
  cin >> T;
  for(int t = 1; t <= T; t++){
    for(int i = 0; i < 111; i++) v[i].clear();

    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> s[i];
      char a = ' ';
      int c = 0;
      ss[i] = "";
      for(int j = 0; j < (int)s[i].size(); j++){
	if(s[i][j] == a){
	  c++;
	}else{
	  if(a != ' '){
	    v[ss[i].size()].push_back(c);
	  }
	  a = s[i][j];
	  ss[i] += s[i][j];
	  c = 1;
	}
      }
      v[ss[i].size()].push_back(c);
    }

    bool f = false;
    for(int i = 1; i < N; i++){
      if(ss[i-1] != ss[i]){
	f = true;
	break;
      }
    }
    if(f){
      cout << "Case #" << t << ": " << "Fegla Won" << endl;
      continue;
    }

    int ans = 0;
    for(int i = 1; i <= (int)ss[0].size(); i++){
      sort(v[i].begin(),v[i].end());
      for(int j = 0; j < (int)v[i].size(); j++){
	ans += abs(v[i][j] - v[i][v[i].size()/2]);
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}
