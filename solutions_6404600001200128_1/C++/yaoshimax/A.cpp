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
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

int main(){
  int n_case;
  cin >> n_case;
  int mash[1001];
  for( int loop = 0 ; loop < n_case ; loop++ ){
   int N;
   cin >> N;
   for(int ni=0;ni<N;ni++){
      cin>>mash[ni];
   }
   int ans1=0;
   int dif=0;
   for( int ni=0;ni+1<N;ni++){
      if(mash[ni]>mash[ni+1]){
         ans1+=mash[ni]-mash[ni+1];
         dif=max(dif,mash[ni]-mash[ni+1]);
      }
   }
   int ans2=0;
   for( int ni=0; ni+1<N; ni++ ){
      if( mash[ni]>dif ) ans2+=dif;
      else ans2+=mash[ni];
   }

   cout << "Case #" << loop+1 << ": " <<ans1<<" " <<ans2<< endl;
  }
  return 0;
}
