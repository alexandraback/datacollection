#include <iostream>
#include <string>
#include <vector>

using namespace std;

int myabs(int x)
{
  if (x < 0)
    return -x;
  return x;
}

const int INF = 1000000000;
string getPattern(const string& s) {
  string ans;
  ans.push_back(s.front());
  for (auto it = s.begin() + 1; it != s.end(); ++it)
    if (*it != ans.back())
      ans.push_back(*it);
  return ans;
}

void fillAmountOfEachCharacter(string s, vector<vector<int>>& amount_ch_str) {
  int pos = 0;
  char ch = s.front();
  int num = 1;
  for (auto it = s.begin() + 1; it != s.end(); ++it)
    if (*it == ch)
      ++num;
    else {
      amount_ch_str[pos].push_back(num);
      num = 1;
      ++pos;
      ch = *it;
    }
  amount_ch_str[pos].push_back(num);
}

int main() {
  
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    cout << "case #" << testcase << ": ";
    int N;
    cin >> N;
    string s0;
    cin >> s0;
    string pattern0 = getPattern(s0);
    vector<vector<int>> amount_ch_str(pattern0.size());
    fillAmountOfEachCharacter(s0, amount_ch_str);
    bool fegla_won = 0;
    for (int i = 1; i < N; ++i) {
      string s;
      cin >> s;
      if (getPattern(s) != pattern0)
        fegla_won = 1;
      else {
        fillAmountOfEachCharacter(s, amount_ch_str);
      }
    }
    if (fegla_won)
      cout << "Fegla Won" << endl;
    else {
      int ans = 0;
      for(size_t pos = 0; pos < amount_ch_str.size(); ++pos) {
        int pos_ans = INF;
        for (int x = 0; x <= 101; ++x) {
          int tmp = 0;
          for (size_t i = 0; i < N; ++i) {
            tmp += myabs(amount_ch_str[pos][i] - x);
          }
          if (tmp < pos_ans)
            pos_ans = tmp;
        }
        ans += pos_ans;
      }
      cout << ans << endl;
    }
  }
  
  /*
  string s;
  cin >> s;
  vector<vector<int>> amount_ch_str(getPattern(s).size());
  fillAmountOfEachCharacter(s, amount_ch_str);
  for (int i = 0; i < amount_ch_str.size(); ++i)
    cout << amount_ch_str[i].front() << " ";
  cout << endl;
  */
  return 0;
}