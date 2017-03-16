#include <iostream>
#include <vector>
using namespace std;

int main() {

  long long int t;
  cin >> t;

  for ( long long int tt = 0; tt < t; tt++ ) {

    cout << "Case #" << tt+1 << ": ";

    long long int n;
    cin >> n;

    vector< long long int > v;

    for ( long long int i = 0; i < n; i++ ) {

      long long int in;
      cin >> in;

      v.push_back( in );

    }

    long long int ans = 0;

    for ( long long int i = 0; i < n - 1; i++ ) {
      if ( v[i] > v[i+1] ) ans += ( v[i] - v[i+1] );
    }
    cout << ans;

    ans = 0;

    long long int rate = 0;
    for ( long long int i = 0; i < n - 1; i++ ) {
      rate = max( rate, v[i] - v[i+1] );
    }
    if ( rate > 0 ) {

      for ( long long int i = 0; i < n - 1; i++ ) {

	if ( v[i] <= rate ) {
	  ans += v[i];
	}else {
	  ans += rate;
	}

      }

    }

    cout << " " << ans << endl;

  }

  return 0;

}
