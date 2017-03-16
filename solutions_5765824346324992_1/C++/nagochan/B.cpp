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

#define MMAX 100000

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    LL B,N;
    cin>>B>>N;
    VLL array;
    REP(i,B)
    {
      int tmps;
      cin>>tmps;
      array.PB(tmps);
    }
    if(B>=N){
      cout<<"Case #"<<t<<": "<<N<<endl;
      continue;
    }
    //2分探索
    LL low = 0;
    LL high = (LL)MMAX * N;
    LL mid = (high + low)/2;
    while(high > low){
      if(high-low == 1)break;
      ll count = 0;
      mid = (high + low)/2;
      for(int b = 0;b<B;b++){
        count += mid/array[b];
      }
      if(count >= (N-B)) {
        high = mid;
      }else {
        low = mid;
      }
#ifdef DEBUG
cout<<"2bun1:"<<high<<","<<low<<","<<count<<endl;
#endif
    }
    mid = high;
    while(low<mid){
      LL mid1 = mid - 1;
      ll count = 0;
      for(int b = 0;b<B;b++){
        count += mid1/array[b];
      }
      if(count < (N-B))break;
      mid--;
    }
#ifdef DEBUG
cout<<"2bun2:"<<mid<<endl;
#endif
    int min_count = 0;
    int min_index = B;
    ll count = 0;
    for(int b = 0;b<B;b++){
      count += (mid-1)/array[b];//1minute前までカウント
    }
#ifdef DEBUG
cout<<"2bun3:"<<count<<endl;
#endif
    int ans = B;
    for(int b =0 ;b<B;b++){
      int m = mid%array[b];
#ifdef DEBUG
cout<<"2bun4:"<<m<<endl;
#endif
      if(m==0){
        min_count++;
        if(N-B == count + min_count){
          ans = b+1;
#ifdef DEBUG
cout<<"2bun5:"<<N-B<<","<<min_count<<","<<ans<<endl;
#endif
          break;
        }
      }
    }
    
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

