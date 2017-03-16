#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

string inp;
int T,n;

int main() {
  ifstream f("ia.txt");
  ofstream g("output.txt");
  f>>T;
  for(int t=1; t<=T; ++t) {
    f>>n; string rz;
    set<pair<int,char> > s;
    int st=0;
    for(int i=0; i<n; ++i) {
      int x; f>>x;
      st+=x;
      s.insert(make_pair(-x,i+'A'));
    }
    while(s.size()) {
      int fr=-s.begin()->first; char b=s.begin()->second;
      //cout<<fr<<' '<<b<<' '<<st<<'\n';
      s.erase(s.begin());
      rz+=b;
      if(fr>1)s.insert(make_pair(-fr+1,b));
      --st;
      //cout<<"SZ"<<s.size()<<'\n';
      if(s.size() && st/2<(-s.begin()->first)) {
        fr=-s.begin()->first; b=s.begin()->second;
        s.erase(s.begin());
        if(fr>1)s.insert(make_pair(-fr+1,b));
        rz+=b;
        --st;
      }
      rz+=" ";
    }
    //cout<<t<<'\n';
    
    g<<"Case #"<<t<<": "<<rz<<'\n';
  }
}