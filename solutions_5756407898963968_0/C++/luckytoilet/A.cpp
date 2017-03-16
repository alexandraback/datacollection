#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#define LL long long
using namespace std;

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}

template<typename T, typename U>
ostream& operator<<(ostream& s, const pair<T,U>& p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}


void skip(int n) {
  for(int i=0; i<4*n; i++){
    int t; cin>>t;
  }
}

int main(){

  int ncases; cin>>ncases;

  for(int nc = 1; nc <= ncases; nc++) {

    int first_row;
    cin>>first_row;

    // skip n-1 lines then read 4 numbers, then skip 4-n lines
    skip(first_row-1);

    vector<int> s1(4,0);
    cin>>s1[0];
    cin>>s1[1];
    cin>>s1[2];
    cin>>s1[3];

    skip(4-first_row);


    int second_row;
    cin>>second_row;

    skip(second_row-1);

    vector<int> s2(4,0);
    cin>>s2[0];
    cin>>s2[1];
    cin>>s2[2];
    cin>>s2[3];

    skip(4-second_row);


    vector<int> intersect;
    for(int i=0; i<4; i++) {
      if(find(s2.begin(),s2.end(),s1[i]) != s2.end()) intersect.push_back(s1[i]);
    }

    cout << "Case #" << nc << ": ";

    if(intersect.size() == 0)
      cout << "Volunteer Cheated!";
    if(intersect.size() > 1)
      cout << "Bad Magician!";
    if(intersect.size() == 1)
      cout << intersect[0];

    cout<<endl;
  }



}

