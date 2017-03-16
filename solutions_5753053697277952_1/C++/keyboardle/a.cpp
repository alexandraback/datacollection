#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void proc(ifstream& ifile) {
  int t = 0, x = 1;
  ifile >> t;
  for(int i = 0; i < t; ++i) {
    cout << "Case #" << (x++) << ":";
    //// TODO ////
    int N = 0, sum = 0;
    ifile >> N;
    vector<int> senators(N);
    for(int j = 0; j < N; ++j) {
      int s = 0;
      ifile >> s;
      sum += s;
      senators[j] = s;
    }
    while(sum > 0) {
      int maj = (sum-2)/2+1;
      vector<int> plan;
      for(int j = 0; j < N; ++j) {
        if(senators[j] >= maj) {
          plan.push_back(j);
          if(plan.size() > 2) break;
        }
      }
      if(plan.size() > 2) {
        int max = 0, idx = 0;
        for(int j = 0; j < plan.size(); ++j) {
          if(senators[plan[j]] > max) {
            max = senators[plan[j]];
            idx = plan[j];
          }
        }
        plan.clear();
        plan.push_back(idx);
      } else if(plan.size() < 2) {
        for(int j = 0; j < N; ++j) {
          if(senators[j] > 0) {
            plan.push_back(j);
            if(plan.size() >= 2) break;
          }
        }
      }
      sum -= plan.size();
      cout << ' ';
      for(int j = 0; j < plan.size(); ++j) {
        cout << (char)('A'+plan[j]);
        --senators[plan[j]];
      }
    }
    //////////////
    cout << endl;
  }
}

int main(int argc, char** argv) {
  if(argc != 2) { cerr << "Wrong usage." << endl; }
  ifstream ifile(argv[1]);

  proc(ifile);

  return 0;
}
