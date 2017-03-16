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
typedef pair<string,int>            PSI;
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
typedef vector<LL>	VLL;

//#define DEBUG

#define INF  100000000000009LL

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    LL R,C,N;
    cin>>R>>C>>N;
    LL n;
    VI A;
    LL ans = INF;
    LL RC = R*C;
    for(n=0;n<RC-N;n++){
      A.PB(0);
    }
    for(n=0;n<N;n++){
      A.PB(1);
    }
    do{
      LL ans_l = 0;
      for(n=0;n<RC;n++){
        if(A[n]==1){
          if((n+R)<RC && A[n+R]==1) ans_l++;
          if((n%R)<R-1 && A[n+1]==1) ans_l++;
        }
      }
      ans = min(ans, ans_l);
    }while(next_permutation(ALL(A)));
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

