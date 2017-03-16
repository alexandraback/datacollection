#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <fstream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

// decreasing order
bool comp(pair<int,int> i, pair<int, int> j) {
  return i.second > j.second;
}

int main() {
  ifstream myfile;
  myfile.open ("awesome.in");
  ofstream a_file ( "example.out" );
  
  int t; myfile >> t;
  
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  for (int i=0; i<t; i++) {
    a_file << "Case #" << i+1 << ": ";
    int n; myfile >> n;

    vector<pair<int,int> > senators;
    for (int j=0; j<n; j++) {
      int cur; myfile >> cur;
      senators.push_back(make_pair(j, cur));
    }
    sort(senators.begin(), senators.end(), comp);
    
    // even out first 2
    int a = senators[0].second - senators[1].second;
    for (int j=0; j<a; j++) {
      a_file << alpha[senators[0].first] << " " ;
    }
    
    // erase the plebs
    for (int j=2; j < senators.size(); j++) {
      for (int k=0; k < senators[j].second; k++) {
        a_file << alpha[senators[j].first] << " " ;
      }
    }
    
    // erase first 2
    for (int j=0; j<senators[1].second; j++) {
      a_file << alpha[senators[0].first] << alpha[senators[1].first] << " ";
    }
    
    a_file << endl;

  }
  
  a_file.close();
}