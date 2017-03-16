#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

vector <int> read_configuration(ifstream & IN) {
     int a;
     vector <vector <int> > B(4, vector<int> (4));
     
     IN>>a;
     for (int i=0; i<4; i++) for (int j=0; j<4; j++) IN>>B[i][j];
     
     vector <int> V=B[a-1];
     sort(V.begin(), V.end());     
     return V;
     }

int main(void) {
     ifstream IN("A-large.in");
     ofstream OUT("A-large.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int N;
          IN>>N;
          
          vector <string> S(N);
          for (int i=0; i<N; i++) IN>>S[i];
          
          bool doable=true;
          int minimal_step=0;
          
          while (S[0].size()>0) {
               char curr=*S[0].rbegin();
               vector <int> A;
               for (int i=0; i<N; i++) {
                    int count=0;
                    string & s=S[i];
                    while (s.size()>0 && (*s.rbegin()==curr)) {
                         s.resize(s.size()-1);
                         count++;
                         }
                    if (count==0) doable=false;
                    else A.push_back(count);
                    }
               sort(A.begin(), A.end());

               assert(doable==false || A.size()==N);
               for (int i=0; i<N; i++) minimal_step+=abs(A[i]-A[N/2]);
               }
          
          for (int i=0; i<N; i++) if (S[i].size()!=0) doable=false;
          
          if (doable) OUT<<"Case #"<<test<<": "<<minimal_step<<"\n";
          else OUT<<"Case #"<<test<<": "<<"Fegla Won"<<"\n";
          }
     return 0;
     }
