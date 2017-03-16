//Done by Mycroft Grey
//Fet per Ferran Alet

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<numeric>
#include<set>
#include<sstream>
#include<list>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;

string convert(string &s, VVI &v){
  string st="";
  char last=s[0];
  int cont=1;
  int pos=0;
  for(int i=1;i<s.size();++i){
    if(s[i]==last) ++cont;
    else {
      v[st.size()].push_back(cont);
      st+=last;
      cont=1;
      last=s[i];
    }
  }
  v[st.size()].push_back(cont);
  st+=last;
  return st;
}

int main(){
  ios_base::sync_with_stdio(false);
  freopen("A-large.out","w",stdout);
  freopen("A-large.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    int n;
    cin>>n;
    VVI v(100);
    string s;
    cin>>s;
    string pat=convert(s,v);
    bool b=true;
    FOR(i,n-1){
      cin>>s;
      if(convert(s,v)!=pat) b=false;
    }
    cout<<"Case #"<<cas<<": ";
    if(!b) cout<<"Fegla Won"<<endl;
    else {
      ll res=0;
      FOR(i,100){
        sort(v[i].begin(),v[i].end());
        FOR(j,v[i].size()){
          res+=abs(v[i][v[i].size()/2]-v[i][j]);
        }
      }
      cout<<res<<endl;
    }
  }
  //system("pause");
}
