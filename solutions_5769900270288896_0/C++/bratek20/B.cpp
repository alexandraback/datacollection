#include<bits/stdc++.h>
using namespace std;
int r,c,n,odp;
void idz(int maska,int x,int ile){
   if(ile==n){
      int cnt=0;
      for(int i=1;i<=r*c;i++){
	 if(i%c!=0){
	    if( (maska&(1<<i)) && (maska&(1<<(i+1)) ) ){
	       //printf("%d +1\n",i);
	       cnt++;
	    }
	 }
	 if(i+c<=r*c){
	    if( (maska&(1<<i)) && (maska&(1<<(i+c)) ) ){
	       //printf("%d +r\n",i);
	       cnt++;
	    }
	 }
      }
      odp=min(odp,cnt);
   }
   if(r*c-x+ile<n)return;
   
   for(int i=x+1;i<=r*c;i++){
      idz(maska+(1<<i),i,ile+1);
   }
}
int main(){
   int t;
   scanf("%d",&t);
   for(int i=1;i<=t;i++){
      odp=1e9;
      scanf("%d%d%d",&r,&c,&n);
      idz(0,0,0);
      printf("Case #%d: %d\n",i,odp);
   }
   return 0;
}