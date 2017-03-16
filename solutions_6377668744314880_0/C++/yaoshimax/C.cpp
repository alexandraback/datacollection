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

long long product( pair<int,int> p1, pair<int,int> p2, pair<int,int> p3 ){
   pair<int,int> v1 = make_pair( p2.first-p1.first, p2.second-p1.second);
   pair<int,int> v2 = make_pair( p3.first-p1.first, p3.second-p1.second);
   return v2.first*(long long)v1.second-v2.second*(long long)v1.first;
}

vector< pair<int,int> > convex_hull( vector<pair<int,int> > &V){
   if( V.size() <=2 ) return V;
   int size = V.size();
   sort(V.begin(),V.end());
   vector<pair<int,int> > ret(size*2);
   int retlen=0; 
   for( int i = 0 ; i <size; i++ ){
      while( retlen >= 2 && product( ret[retlen-2],ret[retlen-1],V[i] ) < 0 ) retlen--;
      ret[retlen++]=V[i];
   }
   int underlen=retlen;
   for( int i = size-2 ; i >= 0 ; i-- ){
      while( retlen > underlen && product( ret[retlen-2],ret[retlen-1],V[i] ) < 0 ) retlen--;
      ret[retlen++]=V[i];
   }
   ret.resize(retlen);
   return ret;
}

int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    int N;
    cin >> N;
    vector<pair<int,int> >points;
    for( int i = 0 ; i < N;i++){
       int x,y;
       cin >> x >> y ;
       points.push_back(make_pair(x,y));
    }
    int ans[N];
    for( int i = 0 ; i < N; i++ ){
      ans[i]=INT_MAX;
    }
    for( int mask=0;mask<(1<<N); mask++){
      vector<pair<int,int> > cur;
      for( int i = 0 ; i<N; i++ ){
         if( (mask&(1<<i)) ) cur.push_back(points[i]);
      }
         vector<pair<int,int> > ch=convex_hull(cur);        
         for( int i = 0 ; i < (int) ch.size(); i++ ){
            for( int j = 0 ; j < N ; j++ ){
               if( points[j]==ch[i] ){
                  ans[j]=min(ans[j],N-(int)cur.size());
               }
            }
         }
    }
    cout << "Case #" << loop+1 << ": " << endl;
    for( int i = 0 ; i < N ; i++ ){
      cout << ans[i] << endl;
    }
  }
  return 0;
}
