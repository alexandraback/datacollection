#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int P[26];
multiset<int> S;

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=1; tt<=T; tt++){
    printf("Case #%d: ",tt);
    cin>>n;
    S.clear();
    int sum=0;
    for(int i=0; i<n; i++){
      scanf("%d",P+i);
      sum+=P[i];
    }

    while(sum>0){
      int a1,b1=-1;
      int a2,b2=-1;

      for(int i=0; i<n; i++)
        if (P[i]>0){
          if (b1==-1 || P[i]>a1){
            a2=a1;
            b2=b1;
            a1=P[i];
            b1=i;
          } else
            if (b2==-1 || P[i]>a2){
              a2=P[i];
              b2=i;
            }
        }

      if (a1>=a2+2){
        cout<<string(2,'A'+b1)<<" ";
        P[b1]-=2;
        sum-=2;
      }else
        if (a1==a2+1 || sum==3){
          cout<<string(1,'A'+b1)<<" ";
          P[b1]-=1;
          sum-=1;
        }else{
          //a1==a2
          cout<<string(1,'A'+b1)<<string(1,'A'+b2)<<" ";
          P[b1]-=1;
          P[b2]-=1;
          sum-=2;
        }
    }

    printf("\n");
  }

  return 0;
}
