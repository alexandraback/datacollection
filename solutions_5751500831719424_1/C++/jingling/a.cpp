#include <algorithm>
#include <numeric>
#include <functional>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;

#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

int main(int argc, char *argv[])
{
  int __T;
  cin>>__T;
  for(int __t = 1 ; __t <= __T; __t++){
    int n;
    cin>>n;
    vector<string> v(n);
    vector<string> p(n);
    vector<vector<int> > d (n, vector <int>(100, 0));

    for(int i = 0 ; i < n; i++){
      cin>>v[i];
      string s = v[i];
      int m = s.size();
      string x = s.substr(0,1);
      int pre=1, pn=0;
      for(int j = 1 ; j < m; j++){
        if(s[j]!=s[j-1]){
          x+=s[j];
          d[i][pn++]=pre;
          pre=1;
        }else{
          pre++;
        }
      }
      d[i][pn]=pre;
      //copy(d[i].begin(), d[i].begin()+pn+1, ostream_iterator<int>(cout, ","));cout<<endl;
      p[i]=x;
    }

    int ok = 1;
    for(int i = 1 ; i < n; i++){
      //cout<<p[i]<<endl;
      if(p[i]!=p[i-1])
        ok=0;
    }

    if(ok==0){
      cout<<"Case #"<<__t<<": Fegla Won"<<endl;
    }else{
      int ans=0;

      for(int j = 0 ; j < p[0].size(); j++)
      {
        vector<int> vv;
        for(int i = 0 ; i < n; i++)
        {
          vv.push_back(d[i][j]);
        }
        sort(vv.begin(), vv.end());
        for(auto yy :vv){
          //cout<<j<<":"<<yy<<" - "<<vv[n/2]<<endl;
          ans+=abs(yy - vv[n/2]);
        }
      }


      cout<<"Case #"<<__t<<": "<<ans<<endl;
    }
  }

    return 0;
}
