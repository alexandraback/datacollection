//Program: a
//Author: gary
//Date: 03/05/2014
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> i2;
typedef long long ll;
const int INF = 1e9;
const int MAX_N = 111;

int T;
string s[MAX_N];
string gform;
int c[MAX_N][MAX_N];
int N;
int main(){
//  ios::sync_with_stdio(0);
  cin >> T;
  for(int caseno = 1; caseno <= T; caseno++){
    cin >> N;
    for(int i = 0; i < N; i++)
      cin >> s[i];
    gform = "";
    memset(c, 0, sizeof c);
    bool bad = false;
    for(int i = 0; i < N; i++){
      string form = "";
      for(int j = 0; j < SZ(s[i]); j++){
	if(form.empty() || form[SZ(form) - 1] != s[i][j])
	  form += s[i][j];
	c[i][SZ(form) - 1] ++;
      }
      if(i == 0) {
	gform = form;
      } else {
	if(form != gform)
	  bad = true;
      }
    }

    printf("Case #%d: ", caseno);
    if(bad){
      cout << "Fegla Won" << endl;
    } else {
      int r = 0;
      for(int i = 0; i < SZ(gform); i++){
	int b = INF;
	for(int j = 1; j <= 100; j++){
	  int g = 0;
	  for(int k = 0; k < N; k++){
	    g += abs(c[k][i] - j);
	  }
	  b = min(b, g);
	}
	r += b;
      }
      cout << r << endl;
    }
  }
  return 0;
}
