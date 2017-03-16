#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdlib>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#define MAX 100005

using namespace std;
int n;

string check(string t){
  int len = t.size();
  string res ="";
  int i = 0;
  while(i < len ){
    char tmp = t[i];
    res += tmp;
    while( i < len && tmp == t[i]){
    	i++;
    }
  }
  return res;
}
bool valid(vector <string> v){
  string first = check(v[0]);
  for( int i = 1; i < v.size(); i++){
    if (first != check(v[i]))  return false;
  }
  return true;
}
vector <int> clean(string t){
  vector <int> X;
  int i = 0;
  while( i < t.size()){
    char c = t[i];
    int sum = 0; 
    while(i < t.size() && c == t[i]){
      i++;
      sum++;
    }
    X.push_back(sum);
  }
  return X;
  
}

void solve(){
  int n;
  scanf("%d",&n);
  string t;
  vector <string> v;
  for( int i = 0; i < n; i++){
    cin >> t;
    v.push_back(t);
  }

  if (!valid(v) ) {
  	puts("Fegla won");
    return;
  }


  vector < vector <int> > join;
  for( int i = 0; i < n; i++){
  	join.push_back(clean(v[i]));
  }
  int m = join[0].size();
  int res = 0;
  for( int j = 0; j < m; j++){
    vector <int> col;
	for( int i = 0; i < n; i++){
    	col.push_back(join[i][j]);
    }
    sort(col.begin(),col.end());
    int sum = 0;
    int center = col[n/2];
	for( int i = 0; i < n; i++){
    	sum += abs(col[i] - center);
    }
    res += sum;
  }
  printf("%d\n", res);
}
int main(){
  int runs;
  scanf("%d",&runs);
  for( int r = 1; r <= runs; r++){
    printf("Case #%d: ",r);
    solve();
  }
  return 0;
}
