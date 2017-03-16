#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MODV 1000000007

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;
void addmod(int &a, ll b){a=(a+b); if(a>=MODV)a-=MODV;}
void mulmod(int &a, ll b){a=(a*b)%MODV;}
int getint(){int a;scanf("%d",&a);return a;}
ll getll(){ll a;scanf("%lld",&a);return a;}

void doit() {
  int n=getint(), tot=0;
  int *a = new int[n]();
  for(auto i=0;i<n;i++){
    scanf("%d", a+i);
    tot+=a[i];
  }
  while(tot){
    vi t, an;
    int ntot=(tot-2)/2;
    for(int i=0;i<n;i++) {
      if(a[i]>ntot){t.pb(i);}
      if(a[i]>0)an.pb(i);
    }
    if(t.size()>3)cerr<<"Something wrong: "<<tot<<endl;
    if(t.size()==3 || t.size()==1){
      printf(" %c",t[0]+'A');
      a[t[0]]--;
      tot--;
    }else if(t.size()==2){
      printf(" %c%c",t[0]+'A',t[1]+'A');
      a[t[0]]--;a[t[1]]--;
      tot-=2;
    }else if(an.size()==1){
      printf(" %c",an[0]+'A');
      a[an[0]]--;
      tot--;
    }else if(an.size()>1){
      printf(" %c%c",an[0]+'A',an[1]+'A');
      a[an[0]]--;a[an[1]]--;
      tot-=2;
    }
  }
  

}

int main() {
  int tc;
  scanf("%d",&tc);
  for(int i=1;i<=tc;i++){
    printf("Case #%d:",i);
    doit();
    printf("\n");
  }
  return 0;
}
