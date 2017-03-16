#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main()
{
  int T, N;
  cin >> T;

  for (int t = 1; t <= T; t++)
    {
      cin >> N;
      vector<string> S (N);
      for (int i = 0; i < N; i++) {
	cin >> S[i];
      }

      int len = -1;
      bool possible = true;
      vector<vector<pair<char,int> > > count (N);
      for (int i = 0; i < N; i++)
	{
	  for (int j = 0; j < S[i].size();) {
	    pair<char,int> c = make_pair(S[i][j], 0);
	    for (; j < S[i].size() && S[i][j] == c.first; j++) {
	      c.second++;
	    }
	    count[i].push_back(c);
	  }

	  if (len == -1) {
	    len = count[i].size();
	  } else {
	    if (len != count[i].size()) {
	      possible = false;
      	      break;
	    }
	  }
	}

      /*for (int i = 0; i < N; i++) {
	for (int j = 0; j < count[i].size(); j++) {
	  printf("%c:%d ", count[i][j].first, count[i][j].second);
	}
	puts("");
	}*/

      if (!possible) {
	printf("Case #%d: Fegla Won\n", t);
	continue;
      }

      int sum = 0;
      for (int i = 0; i < len; i++) {
	char c = count[0][i].first;
	vector<int> freq (N);
	for (int j = 0; j < N; j++) {
	  freq[j] = count[j][i].second;
	  if (count[j][i].first != c) {
	    possible = false;
	    break;
	  }
	}
	if (!possible) break;

	// min sum of dists
	sort(freq.begin(), freq.end());
	int med = freq[N/2];
	for (int j = 0; j < N; j++) {
	  sum += abs(freq[j] - med);
	}
      }

      if (!possible) {
	printf("Case #%d: Fegla Won\n", t);
      } else {
	printf("Case #%d: %d\n", t, sum);
      }
    }

  return EXIT_SUCCESS;
}
