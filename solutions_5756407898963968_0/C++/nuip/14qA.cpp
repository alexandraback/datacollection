#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back
#define pqPair priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef __int64 ll;

int scn(int a[]){
  int n,i,j;
  cin>>n;
  for(i=1;i<=4;i++){
    for(j=0;j<4;j++){
      if(i==n){
        scanf("%d",a+j);
      }else{
        scanf("%*d");
      }
    }
  }
//  for(i=0;i<4;i++)cout<<a[i]<<" ";
 // cout<<endl;
}

int main(){
  int a[4],b[4],T,t,i,j,re=0;
  cin>>T;
  for(t=1;t<=T;t++){
    re=0;
    scn(a);
    scn(b);
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        if(a[i]==b[j]){
          if(re){
            re=-1;
          }else{
            re=a[i];
          }
        }
      }
    }
    cout<<"Case #"<<t<<": ";
    if(re){
      if(re<0){
        cout<<"Bad magician!"<<endl;
      }else{
        cout<<re<<endl;
      }
    }else{
      cout<<"Volunteer cheated!"<<endl;
    }
  }
  return 0;
}