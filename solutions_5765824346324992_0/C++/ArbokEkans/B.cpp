#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
#include <sstream>

using namespace std;

// first k > time with k%rate = 0;
// rate - small
long first_after(long time, int rate) {
  long res = time+1;
  while (res%rate != 0) res++;
  return res;
}


string scase(int t) {
  int B, N;
  cin >> B >> N;
  vector <int> bs(B);
  for (int i=0; i<B; i++) cin >> bs[i];
  
  double rate = 0;
  for (int i: bs) {
    rate += 1.0/((double) i);
  }
  
  long start_time = (N-B)/rate-1;

  int guys_before = 0;
  for (int i: bs) {
    guys_before += (start_time/i + 1);
  }

  

  
  vector<pair<long, int> > events;

  for (int bindex=0; bindex < B; bindex++) {
    long curr_time = first_after(start_time, bs[bindex]);


    for (int i=0; i<2*B; i++) {
      events.emplace_back(curr_time + i*bs[bindex], bindex+1);
    }
  }

  sort(events.begin(), events.end(), [] (const pair<long, int> & a, const pair<long, int> b) -> bool {
      if (a.first != b.first) {
        return a.first < b.first;
      }
      assert (a.second != b.second);
      return a.second < b.second;
    });

  //cout << "guys_before = " << guys_before << endl;

  /*for (auto stuff : events) {
    cout << stuff.first << " " << stuff.second << "\n";
    }*/

  //cout << endl;

  pair<long, int> ev = events[N-guys_before-1];

  
  stringstream hej;
  hej << "Case #" << t << ": " << ev.second << "\n";
  return hej.str();
  
  
}


int main() {
  int T;
  cin >> T;
  
  for (int t=1; t<=T; t++) {
    cout << scase(t);
  }

  cout << endl;

}
