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
     ifstream IN("A-small.in");
     ofstream OUT("A-small.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          vector <int> first_answer=read_configuration(IN);
          vector <int> second_answer=read_configuration(IN);
          
          vector <int> intersection(10);
          vector<int>::iterator it=set_intersection(first_answer.begin(), first_answer.end(), second_answer.begin(), second_answer.end(), intersection.begin());

          intersection.resize(it-intersection.begin());
          
          OUT<<"Case #"<<test<<": ";
          if (intersection.size()>1) OUT<<"Bad magician!"<<"\n";
          else if (intersection.size()==1) OUT<<intersection[0]<<"\n";
          else OUT<<"Volunteer cheated!"<<"\n";
          }
     return 0;
     }
