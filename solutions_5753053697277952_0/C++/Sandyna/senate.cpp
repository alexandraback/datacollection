#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () {
  long long t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    vector<pair<int, char> > amounts (n);
    long long inp, sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> inp;
      sum += inp;
      amounts[j] = make_pair(inp,  char ('A'+j) );
    }
//     cout << "amounts: " << endl;
//     for (int k = 0; k < amounts.size(); k++) {
//       cout << amounts[k].first << " " << amounts[k].second << endl;
//     }
    
    cout << "Case #" << i+1 << ": ";
//     cout << sum << endl;
    sort(amounts.begin(), amounts.end());
    reverse(amounts.begin(), amounts.end());
    if (sum %2 == 1) {
//       cout << "odd\n";
      cout << amounts[0].second << " ";
      amounts[0].first --;
      sum --;
    }
    while (sum > 0) {
      sort (amounts.begin(), amounts.end());
      reverse(amounts.begin(), amounts.end());
//       cout << "amounts: " << endl;
//       for (int k = 0; k < amounts.size(); k++) {
// 	cout << amounts[k].first << " " << amounts[k].second << endl;
//       }
      if (sum > 2) {
	cout << amounts[0].second << amounts[1].second << " ";
      } else {
	cout << amounts[0].second << amounts[1].second << endl;
      }
      amounts[0].first --;
      amounts[1].first --;
      sum -= 2;
    }
  }
}