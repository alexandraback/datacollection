#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

fstream in, out;

int T;
int N;
vector<int> mushs;

long long ans1;
long long ans2;
int temp;

int main() {
  in.open("A-small-attempt0.in", fstream::in);
  out.open("proba-small.out", fstream::out);

  in >> T;
  for (int i = 0; i < T; i++) {
    in >> N;
    mushs.clear();
    for (int j = 0; j < N; ++j) {
      in >> temp;
      mushs.push_back(temp);
    }

    ans1 = 0;
    ans2 = 0;
    int prev = 0;
    long long max_rate = 0;
    for (int k = 0; k < N; ++k) {
      if (k == 0) {
	prev = mushs[k];
      } else {
	if (mushs[k] < prev) {
	  ans1 += prev - mushs[k];
	}
	if (mushs[k] < prev) {
	  if (prev - mushs[k] > max_rate) {
	    max_rate = prev - mushs[k];
	  }
	}
	prev = mushs[k];
      }
    }

    for (int k = 0; k < N - 1; ++k) {
      if (mushs[k] >= max_rate) {
	ans2 += max_rate;
      } else {
	ans2 += mushs[k];
      }
    }
    out << "Case #" << i + 1 << ": " << ans1 << " " << ans2 << endl;
  }
    
  in.close();
  out.close();
  return 0;
}
