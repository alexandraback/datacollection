#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
     int num_test;
     cin>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int N;
          cin>>N;
          
          vector <long long> X(N),Y(N);
          for (int i=0; i<N; i++) cin>>X[i]>>Y[i];
          
          vector <int> L(N, N);
          
          if (N==1) L[0]=0;
          
          for (int k=0; k<N; k++) for (int j=0; j<N; j++) if (k != j) {
               long long dx=X[j]-X[k];
               long long dy=Y[j]-Y[k];
               swap(dx,dy);
               dy*=-1;
               vector <pair<long long, int> > V(N);
               for (int i=0; i<N; i++) {
                    V[i].first=dx*X[i]+dy*Y[i];
                    V[i].second=i;
                    }
               
               sort(V.begin(), V.end());
               
               long long last=V[0].first-1;
               int count_min=0;
               int count_equal=0;
               
               for (int i=0; i<N; i++) {
                    if (V[i].first==last) {
                         count_equal++;
                         }
                    else {
                         count_min+=count_equal;
                         count_equal=1;
                         last=V[i].first;
                         }
                    L[V[i].second] = min( L[V[i].second] , count_min );
                    }
               }
          
          cout<<"Case #"<<test<<":\n";
          for (int i=0; i<N; i++) cout<<L[i]<<"\n";
          }
     return 0;
     }
