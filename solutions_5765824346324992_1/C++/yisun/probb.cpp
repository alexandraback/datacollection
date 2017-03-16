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
int B;
long long N;
vector<long long> times;

int ans;
long long temp;
long long max_time;

long long get_num_started(long long time) {
  long long ret = 0;
  for (int i = 0; i < B; ++i) {
    ret += time / times[i] + 1;
  }
  return ret;
}

int main() {
  in.open("B-large.in", fstream::in);
  out.open("probb-large.out", fstream::out);

  in >> T;
  for (int i = 0; i < T; i++) {
    in >> B >> N;
    ans = 0;
    max_time = 0;
    times.clear();
    for (int j = 0; j < B; ++j) {
      in >> temp;
      times.push_back(temp);
      if (temp > max_time) {
	max_time = temp;
      }
    }
    //    cout << "B " << B << " N " << N << endl;

    long long try_time = 0;
    long long min_try = 0;
    long long max_try = max_time * N;
    while (min_try < max_try) {
      long long next_try = (max_try + min_try) / 2;
      long long num_started = get_num_started(next_try);

      //      cout << " min/max " << min_try << " " << max_try << " next " << next_try << " started " << num_started << endl;
      if (num_started > N) {
	max_try = next_try;
      } else if (num_started < N) {
	min_try = next_try + 1;
      } else {
	min_try = next_try;
	max_try = next_try;
      }
    }

    for (long long k = min_try; k >= 0; --k) {
      //      cout << "k " << k << " " << get_num_started(k) << endl;
      if (get_num_started(k) >= N) {
	try_time = k;
      } else {
	break;
      }
    }

    long long new_fill = N - get_num_started(try_time - 1);
    for (int j = 0; j < B; ++j) {
      if (try_time % times[j] == 0) {
	if (new_fill == 1) {
	  ans = j + 1;
	  break;
	} else {
	  --new_fill;
	}
      }
    }

    out << "Case #" << i + 1 << ": " << ans << endl;
  }
    
  in.close();
  out.close();
  return 0;
}
