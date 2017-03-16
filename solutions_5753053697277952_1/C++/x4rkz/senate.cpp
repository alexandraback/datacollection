#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxi(vector<int> v)
{
  int i = 0;
  for(int j = 0; j < v.size(); ++j) {
    if(v[j] > v[i]) {
      i = j;
    }
  }

  return i;
}

int main()
{
  int T;
  cin >> T;

  for(int i = 1; i <= T; ++i) {
    string s = "";

    int N;
    cin >> N;
    vector<int> parties = vector<int>(N);
    
    int tot = 0;
    for(int j = 0; j < N; ++j) {
      int n;
      cin >> n;

      parties[j] = n;
      tot += n;
    }

    for(int j = 0; j < (tot+1)/2; ++j) { 
      if(s != "") s += " ";

      int M = maxi(parties);
      parties[M]--;

      s += 'A'+M;

      M = maxi(parties);
      if(parties[M] != 0) {
	s += 'A' + M;
	parties[M]--;
      }
    }

    if(tot % 2 == 1) {
      auto c = s[s.size()-3];
      s[s.size()-3] = s[s.size()-2];
      s[s.size()-2] = c;
    }
    
    cout << "Case #" << i << ": " << s << endl;
  }
}
