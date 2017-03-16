#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strings;
string master;
int arr[100][100];

string shorten(string wow) {
  string answer;
  for (int i = 0; i < wow.size(); ++i) {
    if (answer.size() == 0 || wow[i] != answer[answer.size()-1]) {
      answer += wow[i];
    }
  }
  return answer;
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n; cin >> n;
    vector<string> strings;
    for (int i = 0; i < n; ++i) {
      string s; cin >> s; strings.push_back(s);
    }
    master = shorten(strings[0]);
    bool okay = true;
    for (int i = 0; i < n; ++i) {
      if (shorten(strings[i]) != master) okay = false;
    }
    cout << "Case #" << test << ": ";
    if (!okay) {
      cout << "Fegla Won" << endl;
      continue;
    }
    int m = master.size();
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; ++i) {
      int curr_idx = 0;
      for (int j = 0; j < strings[i].size(); ++j) {
        if (strings[i][j] == master[curr_idx]) {
          arr[i][curr_idx]++;
        } else {
          curr_idx++;
          arr[i][curr_idx]++;
        }
      }
    }

    int total = 0;
    for (int j = 0; j < m; ++j) {
      int curr_best = 100*100;
      for (int guess = 0; guess <= 100; ++guess) { 
        int inner = 0;
        for (int i = 0; i < n; ++i) {
          inner += abs(guess - arr[i][j]);
        }
        curr_best = min(inner, curr_best);
      }
      total += curr_best;
    }

    cout << total << endl;
  }
  return 0;
}