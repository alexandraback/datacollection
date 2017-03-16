#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;


pair<int, int> eat(vector<int> &s)
{
  int fm = 0;
  int r = 0;
  for ( size_t i = 1; i < s.size(); ++i )
  {
    int diff = s[i - 1] - s[i];
    r = max(r, diff);
    if ( diff > 0 )
      fm += diff;
  }
  int sm = 0;
  for ( size_t i = 0; i + 1 < s.size(); ++i )
    sm += std::min(r, s[i]); 
  return make_pair(fm, sm);
}


int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    cin >> N;
    vector<int> S(N);
    for ( int i = 0; i < N; ++i )
      cin >> S[i];
    auto p = eat(S);
    cout << "Case #" << t << ": " << p.first << ' ' << p.second << '\n';
  }
  return 0;
}
