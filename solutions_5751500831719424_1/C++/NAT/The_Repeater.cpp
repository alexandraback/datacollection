#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N;
string temp;
bool can;
int ans;
int v1, v2, a1, a2;
int a[105];

struct node{
  string s;
  vector<int> c;
}in[105];

int ab( int x){
  if( x < 0)return -x;
  return x;
}

int main(){
  int i, j, k;

  freopen( "A-large.in", "r", stdin);
  freopen( "The_Repeater_l.txt", "w", stdout);

  scanf("%d", &T);
  for( int tt = 1; tt <= T; tt++){
    scanf("%d", &N);
    for( i = 0; i < N; i++){
      cin >> temp;

      in[i].s.clear();
      in[i].c.clear();

      for( j = 0; j < temp.size(); j++){
	if( j == 0 || in[i].s[ in[i].s.size() - 1] != temp[j]){
	  in[i].s += temp[j];
	  in[i].c.push_back( 1);
	}
	else in[i].c[ in[i].c.size() - 1] ++;
      } 
    }

    can = true;
    for( i = 1; i < N && can; i++)
      if( in[0].s != in[i].s)can = false;

    printf("Case #%d: ", tt);
    
    if( !can)printf("Fegla Won\n");
    else{
      ans = 0;
      for( i = 0; i < in[0].s.size(); i++){
	for( j = 0; j < N; j++)
	  a[j] = in[j].c[i];

	sort( a, a + N);
	if( N % 2 == 0)
	  v1 = ( a[N / 2 - 1] + a[N / 2]) / 2;
	else
	  v1 = a[N / 2];
	
	v2 = v1 + 1;

	a1 = a2 = 0;
	for( j = 0; j < N; j++){
	  a1 += ab( a[j] - v1);
	  a2 += ab( a[j] - v2);
	}

	ans += min( a1, a2);
      }

      printf("%d\n", ans);
    }
  }
}
