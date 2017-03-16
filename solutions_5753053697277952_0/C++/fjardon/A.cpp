#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<unsigned,unsigned> uu;
typedef pair<ull,ull> ullull;
typedef pair<string,string> ss;
typedef vector<ss> vss;

template <class K, class V>
using dict = unordered_map<K, V>;

template <class K>
using hset = unordered_set<K>;

typedef pair<ull,char> uc;


int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ull T;
  cin >> T;
  for(ull t=1; t<=T; ++t) {
    cout << "Case #" << t << ":";
    cout << flush;

    ull N;
    cin >> N;
    set<uc> senators;
    char party = 'A';
    ull nb_senators = 0;
    for(ull i=0; i<N; ++i) {
      ull P;
      cin >> P;

      senators.insert(make_pair(P, party));
      ++party;
      nb_senators += P;
    }

    while(! senators.empty()) {
      cout << " ";
      
      auto p1 = *senators.rbegin();
      senators.erase(p1);
      auto p2 = *senators.rbegin();

      
      cout << p1.second << flush;
      --p1.first;
      nb_senators --;

      if(p1.first >= p2.first) {
	--p1.first;
	nb_senators --;
	cout << p1.second;
      }
      
      else if(p2.first > p1.first) {
	senators.erase(p2);
	if(! senators.empty()) {
	  auto p3 = *senators.rbegin();
	  if(p3.first > (nb_senators-1)/2) {
	    senators.insert(p2);
	    if(p1.first)
	      senators.insert(p1);
	    continue; 
	  }
	}
	cout << p2.second << flush;
	--p2.first;
	nb_senators--;
	if(p2.first)
	  senators.insert(p2);
      }
      
      if(p1.first)
	senators.insert(p1);
    }
    cout << "\n";
  }
}
