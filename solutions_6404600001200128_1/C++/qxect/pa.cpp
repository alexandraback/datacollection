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

int arr[2000];

int main()
{
  int T, n;
  int ansA, ansB;
  int maxEat, thisEat, LastM;

  cin >> T;
  for(int z=1;z<=T;z++){
    ansA = ansB = 0;
    maxEat = 0;
    cin >> n;
    for(int i=0;i<n;i++)
      cin >> arr[i];
    
    /* ansA */
    for(int i=0;i+1<n;i++)
      if(arr[i+1] < arr[i])
        ansA += (arr[i] - arr[i+1]);
    
    /* ansB */
    for(int i=0;i+1<n;i++)
      maxEat = max(maxEat, arr[i] - arr[i+1]);

    for(int i=0;i<n;i++){
      if(i==0)
        LastM = arr[0];
      else{
        thisEat = min(LastM, maxEat);
        ansB += thisEat; LastM -= thisEat;
        LastM = arr[i];
      }
    }


    printf("Case #%d: %d %d\n", z, ansA, ansB);
  }
  return 0;
}
