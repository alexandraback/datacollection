#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = 26;

int n;
pq<ii>g;

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    g.push(ii(x, i));
  }
  while(!g.empty()) {
    ii a1 = g.top(); g.pop();
    char c1 = a1.S + 'A';
    a1.F--;
    if(g.size() == 1) {
      ii a2 = g.top(); g.pop();
      if(a1.F + 1 != a2.F) {
        printf(" %c", c1);
      }
      else {
        a2.F--;
        char c2 = a2.S + 'A';
        printf(" %c%c", c1, c2);
      }
      if(a2.F) g.push(a2);
      if(a1.F) g.push(a1);  
    }
    else {
      if(a1.F) g.push(a1);
      printf(" %c", c1);
      if(g.size() == 1) {
        a1 = g.top(); g.pop();
        char c2 = a1.S + 'A';
        a1.F--;
        if(a1.F) g.push(a1);
        printf("%c", c2);
      }
    }
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}