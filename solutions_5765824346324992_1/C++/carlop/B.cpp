#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

long long how_many_before(const vector <long long> & M, int B, long long T) {
     long long R=0;
     for (long long i=0; i<B; i++) {
          R+=(T+M[i]-1)/M[i];
          }
     return R;
     }

int barber_at(const vector <long long> & M, int B, long long T, long long waiting) {
     for (long long i=0; i<B; i++) if (T%M[i] == 0) {
          if (waiting==1) return i+1;
          waiting--;
          }
     return -1;
     }

int find_barber(const vector <long long> & M, int B, long long T, long long N) {
     long long waiting=N-how_many_before(M,B,T);
     
     if (waiting <= 0) return B+1;
     
     return barber_at(M,B,T,waiting);
     }
     

int main(void) {
     int num_test;
     cin>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int B;
          long long N;
          cin>>B>>N;
          
          vector <long long> M(B);
          for (int i=0; i<B; i++) cin>>M[i];
          
          long long OVER=1;
          while (find_barber(M,B,OVER,N) <= B) {
               OVER*=2;
               }
          
          long long UNDER=0;
          
          while (UNDER+1<OVER) {
               long long MIDDLE=(UNDER+OVER)/2;
               if (find_barber(M,B,MIDDLE,N) <= B) UNDER=MIDDLE;
               else OVER=MIDDLE;
               }
          
          cout<<"Case #"<<test<<": "<<find_barber(M,B,UNDER,N)<<"\n";
          }
     return 0;
     }
