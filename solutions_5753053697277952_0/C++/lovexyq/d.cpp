#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstdio>
#include<ctime>
using namespace std;
int n,cur;
int p[30];
void sub(int s){
  p[s]--;
  if(p[s]==0){
    cur--;
  }
}
void cal(){
  if(cur>2){
    int t = 0;
    for(int i=0;i<n;i++){
      if(p[i]>p[t]){
        t = i;
      }
    }
    printf(" %c",'A'+t);
    sub(t);
  } else {
    vector<int> m;
    for(int i=0;i<n;i++){
      if(p[i]>0){
        m.push_back(i);
      }
    }
    if(p[m[0]]==p[m[1]]){
      printf(" %c%c",'A' + m[0],'A' + m[1]);
      sub(m[0]);
      sub(m[1]);
    } else {
      int x = m[0];
      if(p[m[1]]>p[m[0]]){
        x=m[1];
      }
      printf(" %c",'A'+x);
      sub(x);
    }
  }
}
int main(){
  int T;
  scanf("%d",&T);
  for(int cas=1;cas<=T;cas++){
    scanf("%d",&n);
    //printf("n = %d\n",n);
    for(int i=0;i<n;i++){
      scanf("%d",&p[i]);
    }
    cur = n;
    printf("Case #%d: ",cas);
    while(cur>0){
      cal();
    }
    printf("\n");
  }
  return 0;
}