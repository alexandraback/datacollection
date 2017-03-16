#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef long long LL;
typedef pair<int,int>            PI;
typedef map<PI, int> MPI;
typedef vector<int>	VI;
typedef vector< vector<int> >	VII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair

//•’Ê‚Ìgcd(Å‘åŒö–ñ”)
LL gcd(LL x,LL y)
{
  if(y>x)swap(x,y);
  LL m = x%y;
  if(m==0)return y;
  return gcd(y,m);
}

//•’Ê‚Ìlcm(Å¬Œö”{”)
LL lcm(LL x,LL y)
{
  return (x/gcd(x,y))*y;
}

int main(void)
{
  int T,t;
  ll ret;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    ll N;
    cin>>N;
    VI array;
    array.clear();
    for(int n = 0;n<N;n++){
      int tmp;
      cin>>tmp;
      array.PB(tmp);
    }
    //1‚Â‚ß
    int ans1 = 0;
    for(int n = 0;n<N-1;n++){
      int diff = array[n] - array[n+1];
      if(diff > 0) ans1+=diff;
//cout<<"ans1:"<<diff<<","<<n<<endl;
    }
    //2‚Â‚ß
    int ans2 = 0;
    int diff_max = 0;
    for(int n = 0;n<N-1;n++){
      int diff = array[n] - array[n+1];
      diff_max = max(diff, diff_max);
    }
    for(int n = 0;n<N-1;n++){
      ans2 += min(array[n], diff_max);
    }

    cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;
  }
  return 0;
}

