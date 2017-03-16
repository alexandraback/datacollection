#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

void print_vector(vi v);
void print_array(int* array, int start, int end);

#define FOR(i,a,b) for (int i = (a),_b = (b); i < _b; i++)
#define DOW(i,b,a) for (int i = (b),_a = (a); i >= _a; i--)
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ((n >> b) & 1)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()

#define INF 1e9
#define PI acos(-1.0)

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

int tc, cse=1, n, m[1010];

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif 
  s(tc);
  while(tc--){
    s(n);
    FOR(i, 0, n) s(m[i]);
    int ans1 = 0;
    int ans2 = 0;
    FOR(i, 0, n-1){
      if(m[i+1] < m[i]) ans1 += m[i] - m[i+1];
      //printf("%d\n", ans1);
    }
    int maxi = 0;
    FOR(i, 0, n-1){
      maxi = max(maxi, m[i] - m[i+1]);
    }
    FOR(i, 0, n-1){
      ans2 += min(maxi, m[i]);
    }
    printf("Case #%d: %d %d\n", cse++, ans1, ans2);
    // double begin = 0, end = 10010;
    // while(end - begin < 0.0000001){
    //   double mid = (begin + end)/2;
    //   bool can = true;
    //   int c = m[0];
    //   FOR(i, 0, n-1){
    //     c = max(0, (int)(c - 10.0 * mid));
    //     if(mid == 0) printf("%d\n", c);
    //     if(c > m[i+1]) {
    //       can = false; 
    //     }
    //     c = m[i+1];
    //   }
    //   if(can == false){
    //     begin = mid+1;
    //   } else {
    //     end = mid;
    //   }
    // }
    // int c = m[0];
    // FOR(i, 0, n-1){
    //   ans2 += c - max(0, (int)( c - 10.0 * begin));
    //   c = m[i+1];
    // }
    
  }
  return 0;
}

void print_array(int* array, int start, int end){
  printf("[");
  FOR(i, start, end){
    printf("%d ", array[i]);
  }
  printf("]");
  printf("\n");
}

void print_vector(vi v){
  printf("[");
  FOR(i, 0, v.size()){
    printf("%d ", v[i]);
  }
  printf("]");
  printf("\n");
}