#include <bits/stdc++.h>
// g++ -std=c++11 -W -Wall -Werror foo.cpp -o foo 

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> ii;
const int MaxN = 30;

int N, p[MaxN];

char slovo(int z){
  return 'A' + z;
}

void prog(){
  set <ii> S;
  scanf("%d", &N);
  REP(i, N){
    scanf("%d", p + i);
    S.insert(ii(-p[i], i));
  }

  while ((*S.begin()).x != -1){
    ii begy = *S.begin();
    S.erase(S.begin());
    ii drugy = *S.begin(); //postojat ce jer nije bila abs majority
    S.erase(S.begin());
    if (S.empty()){ //moraju biti jednaki begy i drugy
      printf("%c%c ", slovo(begy.y), slovo(drugy.y));
      begy.x++; drugy.x++;
    }
    else{
      if (drugy.x == -1){
	if (begy.x == -1){
	  printf("%c" , slovo(begy.y));
	  begy.x++;
	}
	else{
	  printf("%c%c ", slovo(begy.y), slovo(begy.y));
	  begy.x += 2;
	}
      }
      else{
	printf("%c%c ", slovo(begy.y), slovo(drugy.y));
	begy.x++; drugy.x++;
      }
    }

    if (begy.x < 0)
      S.insert(begy);
    if (drugy.x < 0)
      S.insert(drugy);
  }
  
  while (!S.empty()){
    ii begy = *S.begin();
    S.erase(S.begin());
    if (S.size() == 1){
      ii drugy = *S.begin();
      S.erase(S.begin());
      printf("%c%c ", slovo(begy.y), slovo(drugy.y));
    }
    else{
      printf("%c ", slovo(begy.y));
    }
  }
}

int main(){
  int T;
  cin>>T;
  REP(cas, T){
    printf("Case #%d: ", cas + 1);
    prog();
    printf("\n");
  }
  return 0;
}
