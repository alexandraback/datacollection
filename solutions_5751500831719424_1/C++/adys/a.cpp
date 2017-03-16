#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solve(int N, vector<string> &words)
{
  vector<vector<char>> chars(N,vector<char>());
  vector<vector<int>> lens(N,vector<int>());
  for (int i = 0; i < N; ++i) {
    chars[i].push_back(words[i][0]); 
    lens[i].push_back(1);
  }

  for (int i = 0; i < N; ++i) {
    auto it = words[i].begin();
    for (it++; it != words[i].end(); ++it) {
      if (chars[i].back() != *it) {
        chars[i].push_back(*it);
        lens[i].push_back(1);
      }
      else
        lens[i].back()++;
    }
  }

  auto check = chars[0];
  for (auto a : chars)
    if (a != check)
      return -1;

  int total = 0;
  for (int i = 0; i < lens[0].size(); ++i) {
    int best = 100000;
    for (int n = 1; n < 101; ++n) {
      int sum = 0;
      for (int j = 0; j < words.size(); ++j)
        sum += abs(n - lens[j][i]);
      best = min(best,sum);
    }
    total += best;
  }
  return total;
}

int main()
{
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N; cin >> N;
    vector<string> words;
    for (int n = 0; n < N; ++n) {
      string word; cin >> word;
      words.push_back(word);
    }
    int res = solve(N,words);
    if (res != -1) 
      cout << "Case #" << t << ": " << res << endl;
    else
      cout << "Case #" << t << ": Fegla Won" << endl;
  }
  return 0;
}
