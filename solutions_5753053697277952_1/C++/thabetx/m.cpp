#include <bits/stdc++.h>
using namespace std;

int main(){
  int T;cin>>T;
  for(int t=0;t<T;t++){
    cout<<"Case #"<<t+1<<": ";
    int n;cin>>n;
    int a[100];
    for(int i=0;i<n;i++)cin>>a[i];

    int mx,mx2,idx,idx2;
    while(1){
      mx=0,mx2=0;
      for(int i=0;i<n;i++){
        if(a[i]>mx)mx=a[i],idx=i;
        else if(a[i]==mx)mx2=mx,idx2=i;
      }
      if(mx==1)break;
      else if(mx==mx2){
        cout<<char('A'+idx)<<char('A'+idx2)<<" ";
        a[idx]--,a[idx2]--;
      }
      else cout<<char(idx+'A')<<" ",a[idx]--;;
    }
    for(int i=0;i<n-2;i++)cout<<char('A'+i)<<" ";
    cout<<char('A'+n-2)<<char('A'+n-1)<<" ";
    cout<<endl;
  }
}

