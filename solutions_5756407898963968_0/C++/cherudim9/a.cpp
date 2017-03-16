#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int a[100][100], T;
int b[20];

void doit(){
  int r;
  cin>>r;
  Rep(i,1,4)
    Rep(j,1,4){
    int x;
    cin>>x;
    if (i==r)
      b[x]++;
  }
}

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  cin>>T;
  Rep(tt,1,T){
    cout<<"Case #"<<tt<<": ";

    memset(b,0,sizeof b);
    doit();
    doit();

    int i=find(b,b+19,2)-b;
    //cout<<i<<endl;
    if (i==19)cout<<"Volunteer cheated!"<<endl; else
      if (count(b,b+19,2)>1) cout<<"Bad magician!"<<endl; else
        cout<<i<<endl;
  }
  return 0;
}
