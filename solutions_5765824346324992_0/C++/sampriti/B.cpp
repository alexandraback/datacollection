// Haircut

#include <iostream>
#include <climits>
#include <set>

using namespace std;

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++){
    int B, N; cin >> B >> N;
    int A[B];
    int min_time_step = INT_MAX;
    int curr_cust = 1;
    for(int i = 0; i < B; i++){
      cin >> A[i];
      min_time_step = min(min_time_step, A[i]);
    }
  }
}
