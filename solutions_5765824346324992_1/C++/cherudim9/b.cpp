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

int m, n;
int a[1000+10], b[1000+10];

int pred(long long time){
  long long num=0, rea=0;
  int ret=0;
  for(int i=0; i<n; i++)
    if (time>0)
      num+=(time-1)/a[i]+1;
  for(int i=0; i<n; i++)
    if (time%a[i]==0){
      b[++rea]=i+1;
    }
  //  cout<<time<<" num:"<<num<<" rea:"<<rea<<endl;
  if (num+rea<m)
    return -1;
  if (num<m && m<=num+rea)
    return b[m-num];
  return 0;
}

void solve(){
  long long l=0, r=(long long)1e15;
  while(l<r){
    long long mid=(l+r)/2;
    if (pred(mid)>=0)
      r=mid;
    else
      l=mid+1;
  }
  cout<<pred(l)<<endl;
}

int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);

  int TT;
  cin>>TT;
  for(int tt=1; tt<=TT; tt++){
    printf("Case #%d: ", tt);
    cin>>n>>m;
    for(int i=0; i<n; i++)
      scanf("%d",a+i);
    solve();
  }

  return 0;
}
