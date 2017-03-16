#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin>>T;
  for(int i=1;i<=T;i++){
    int B,N;
    cin>>B>>N;
    int M[1000];
    for(int i=0;i<B;i++){
      cin>>M[i];
    }
    int wt[1000]={};
    int ans;
    bool j=false;
    for(int i=0;i<N;i++){
      int mwt=1e9;
      for(int j=0;j<B;j++){
	mwt=min(mwt,wt[j]);
      }
      for(int j=0;j<B;j++){
	wt[j]-=mwt;
      }

      if(!j&&i&&all_of(wt,wt+B,[](int x){return x==0;})){
	int ci=(N/i-1)*i;
	j=true;
	i=max(i,ci);
      }

      for(int j=0;j<B;j++){
	if(wt[j]==0){
	  wt[j]=M[j];
	  ans=j+1;
	  break;
	}
      }
    }
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
}
