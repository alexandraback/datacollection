#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) (int((a).size()))
#define all(a) (a).begin(), (a).end()

#define For(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef complex<int> cI;
typedef complex<double> cD;

typedef pair<int,int> pI;
typedef pair<ll, ll> pL;

ll B, N;
ll Tim[10];

ll haash(){
  ll t = 0, minT;

  minT = Tim[0];
  for(int i=0; i<B;i++)
    minT = min(minT, Tim[i]);

  for(int i=0;i<B;i++){
    t = t*100LL + (Tim[i] - minT);
  }
  return t;
}

int M[2000];
int sav[30000000];

int main()
{
  int T;
  ll ans;

  cin >> T;
  for(int z=1;z<=T;z++){
    cin >> B >> N;
    ans = -1;
    
    for(int i=0; i<B; i++){
      cin >> M[i];
      Tim[i] = 0;
    }

    map<ll, int> num;
    pL minB;
    ll now, Pre, Len;

    num[haash()] = 0;

    for(ll i=1;i<=N; i++){
      //cout << i << ": ";

      minB = mp(Tim[0], 0);
      for(ll j=1;j<B;j++)
        minB = min(minB, mp(Tim[j], j));

      sav[i-1] = minB.y;
      Tim[minB.y] += M[minB.y];
/*
      for(int j=0;j<B;j++)
        printf("%lld ", Tim[j]);
      puts("");
*/
      now = haash();
      if(num.count(now)==1){
        Pre = num[now];
        Len = (i) - (Pre);
        ans = sav[(N - Pre - 1) % Len];
//        printf("Pre %lld Len %lld To %lld\n", Pre, Len, (N-Pre)%Len);

        break;
      }else num[now] = i;
    }
    if(ans == -1) ans = sav[N];



    printf("Case #%d: %lld\n", z, ans+1);
  }
  return 0;
}
