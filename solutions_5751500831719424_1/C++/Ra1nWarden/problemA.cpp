#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

string shrink(string& str) {
  string result = str.substr(0, 1);
  char prev = str[0];
  for(int i = 1; i < str.length(); i++) {
    if(str[i] != prev) {
      prev = str[i];
      result += str.substr(i, 1);
    }
  }
  return result;
}

int solve(vector<string>& wordlist) {
  string shrinked = shrink(wordlist[0]);
  for(int i = 1; i < wordlist.size(); i++) {
    if(shrink(wordlist[i]) != shrinked)
      return -1;
  }
  vector<vector<int> > freq;
  for(int i = 0; i < wordlist.size(); i++) {
    vector<int> eachwordfreq;
    string currentword = wordlist[i];
    char prev = currentword[0];
    int counter = 1;
    for(int j = 1; j < currentword.length(); j++) {
      if(currentword[j] == prev)
	counter++;
      else {
	eachwordfreq.push_back(counter);
	counter = 1;
	prev = currentword[j];
      }
    }
    eachwordfreq.push_back(counter);
    freq.push_back(eachwordfreq);
  }
  int result = 0;
  for(int i = 0; i < shrinked.size(); i++) {
    vector<int> eachcol;
    int targetnumber = 0;
    for(int j= 0; j < freq.size(); j++)
      eachcol.push_back(freq[j][i]);
    sort(eachcol.begin(), eachcol.end());
    if (eachcol.size() % 2 == 0) {
      int first = eachcol[eachcol.size() / 2 ];
      int second = eachcol[eachcol.size() / 2 - 1];
      targetnumber = (first + second) / 2;
    }
    else
      targetnumber = eachcol[eachcol.size() / 2];
    for(int j = 0; j < eachcol.size(); j++)
      result += abs(targetnumber - eachcol[j]);
  }
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int words;
    cin >> words;
    cin >> ws;
    vector<string> wordlist;
    for(int j = 0; j < words; j++) {
      string word;
      getline(cin, word);
      wordlist.push_back(word);
    }
    int result = solve(wordlist);
    if (result < 0)
      cout << "Case #" << i+1 << ": " << "Fegla Won" << endl;
    else
      cout << "Case #" << i+1 << ": " << result << endl;
  }
  return 0;
}
