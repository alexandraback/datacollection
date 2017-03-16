#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

#define eps 1e-10
int a[17];

int main() {  
  //ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  for(int z=1; z<=t; z++) {
    cout<<"Case #"<<z<<": ";
    memset(a,0,sizeof(a));
    int p,b;
    cin>>p;
    //cout<<"P1: "<<p<<endl;
    for(int i=1; i<=4; i++) {
      for(int j=1; j<=4; j++) {
	cin>>b;
	if(i==p) a[b]++;
      }
    }
    cin>>p;
    //cout<<"P2: "<<p<<endl;
    for(int i=1; i<=4; i++) {
      for(int j=1; j<=4; j++) {
	cin>>b;
	if(i==p) a[b]++;
      }
    }
    int tot = 0,ans;
    //for(int i=1; i<=16; i++) cout<<a[i]<<" ";
    //cout<<endl;
    for(int i=1; i<=16; i++) {
      if(a[i]==2) {
	//cout<<"Found: "<<i<<endl;
	tot++;
	ans = i;
      }
    }
    if(tot==1) cout<<ans<<endl;
    else if(tot==0) cout<<"Volunteer cheated!"<<endl;
    else cout<<"Bad magician!"<<endl;
  }


  return 0;
}
