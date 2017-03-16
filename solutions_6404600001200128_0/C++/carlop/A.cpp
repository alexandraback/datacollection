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
          
          vector <long long> A(N);
          for (int i=0; i<N; i++) cin>>A[i];
          
          long long Y=0,Z=0;
          
          long long S=0;
          for (int i=0; i<N; i++) {
               if (A[i] < S) Y+=S-A[i];
               S=A[i];
               }
          
          long long R=0;
          for (int i=1; i<N; i++) R=max(R, A[i-1]-A[i]);
          for (int i=1; i<N; i++) {
               Z+=min(R, A[i-1]);
               }
          
          cout<<"Case #"<<test<<": "<<Y<<" "<<Z<<"\n";
          }
     return 0;
     }
