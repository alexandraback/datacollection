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
  for( int loop = 0 ; loop < n_case ; loop++ ){
   int N;
   cin >> N;
   priority_queue<pair<int,int> > pq;
   for( int i = 0 ; i < N; i++){
      int P;
      cin >> P;
      pq.push(make_pair(P,i));
   }
   cout << "Case #" << loop+1 << ": ";
   while(pq.size()!=0){
      pair<int,int> p=pq.top();
      pq.pop();
      pair<int,int> q=pq.top();
      pq.pop();
      if( p.first > q.first+1 ){
         p.first-=2;
         cout <<(char)('A'+p.second);
         cout <<(char)('A'+p.second);
         cout <<" ";
      }
      else if(p.first == q.first+1 || pq.size()==1 ){
         p.first-=1;
         cout <<(char)('A'+p.second);
         cout <<" ";
      }
      else{
         p.first-=1;
         q.first-=1;
         cout <<(char)('A'+p.second);
         cout <<(char)('A'+q.second);
         cout <<" ";      
      }
      if(p.first!=0 )pq.push(p);
      if(q.first!=0 )pq.push(q);
   }
   cout << endl;
  }
  return 0;
}
