#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <utility>

using namespace std;

int n, a[1000+10];
int eaten;

bool ok(int rate){
  eaten=0;
  for(int i=1, last=a[0]; i<n; i++){
    eaten+=min(rate,last);
    last=max(last-rate,0);
    if (last>a[i])
      return 0;
    last=a[i];
  }
  return 1;
}

void solve(int &ans){
  int l=0, r=10000+10;
  while(l<r){
    int mid=(l+r)/2;
    if (ok(mid))
      r=mid;
    else
      l=mid+1;
  }
  ok(l);
  ans=eaten;
}

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);

  int TT;
  cin>>TT;
  for(int tt=1; tt<=TT; tt++){
    printf("Case #%d: ", tt);
    cin>>n;
    for(int i=0; i<n; i++)
      scanf("%d",a+i);
    int x=0, y=0;
    solve(y);
    for(int i=1; i<n; i++){
      if (a[i]<a[i-1])
        x+=a[i-1]-a[i];
    }
    cout<<x<<" "<<y<<endl;
  }

  return 0;
}
