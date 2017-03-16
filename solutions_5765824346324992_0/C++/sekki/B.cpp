#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

bool compfun(pair<long long, long long> a, pair<long long, long long> b) {
  return ((a.second < b.second) || ((a.second == b.second) && (a.first < b.first)));
}

int gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b%a;
    b = c;
  }
  return b;
}

int main() {

  long long ncases;
  cin >> ncases;

  for (long long i = 0; i < ncases; i++) {
    long long nbarb, n;
    cin >> nbarb >> n;

    vector<long long> tbarb;
    long long lcm = 1;
    for (long long j = 0; j < nbarb; j++) {
      long long t;
      cin >> t;
      lcm *= (t / (gcd(lcm,t)));     

      tbarb.push_back(t);
    }

    int cust_per_cycle = 0;
    for (int j = 0; j < nbarb; j++) {
      cust_per_cycle += (lcm / tbarb[j]);
    }

    int cycles = (n-1)/cust_per_cycle;
    long long customers = 0;
    vector<pair<long long, long long> > barbtime;
    for (long long j = 0; j < nbarb; j++) {
      long long ncust = cycles * (lcm / tbarb[j]);
      barbtime.push_back(make_pair(j, ncust*tbarb[j]));
      customers += ncust;
    }

    for (long long c = 0; c < n-customers-1; c++) {
      sort(barbtime.begin(), barbtime.end(), compfun);
      barbtime[0].second += tbarb[barbtime[0].first];
    }
    sort(barbtime.begin(), barbtime.end(), compfun);
    
    cout << "Case #" << i+1 << ": " << barbtime[0].first+1 << endl;

  }

  return 0;
}
