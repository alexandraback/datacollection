#include<cstring>
#include<iostream>
#include<bitset>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
#include<iomanip>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define imprime(v) for(int X=0;X<v.size();X++) cout<<printf("%d "); printf("\n");
#define grid(v) for(int X=0;X<v.size();X++){for(int Y=0;Y<v[X].size();Y++) printf("%d ",v[X][Y]); printf("\n");}
#define endl "\n"
const int INF= 0x3f3f3f3f;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
void solve(int t){
  int n;
  cin>>n;
  vi v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int soma=0;
  for(int i=0;i<n;i++) soma+=v[i];
  cout<<"Case #"<<t<<": ";
  while(soma>0){
    int maior=0;
    int idx;
    int idx2;
    int segundo_maior=0;
    for(int i=0;i<n;i++)
      if(v[i]>maior){ maior=v[i], idx=i;}
    v[idx]--;
    for(int i=0;i<n;i++){
      if(v[i]>segundo_maior)
        segundo_maior=v[i],idx2=i;
      if(v[i]==segundo_maior and idx!=i){
        segundo_maior=v[i], idx2=i;
      }
    }
    v[idx2]--;
    if(soma==3){
      v[idx2]++;
      soma--;
      char r='A'+idx;
      cout<<r<<" ";
    }
    else{
      soma-=2;
      char r='A'+idx;
      char r2='A'+idx2;
      cout<<r<<r2<<" ";
    }
  }
  cout<<endl;
}
int main()
{
  BUFF;
  int t;
  cin>>t;
  for(int i=1;i<=t;i++) solve(i);
  return 0;
}
