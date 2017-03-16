#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;
vector<int> data;
int t,b,n,num;
bool solve(long long lnum,long long unum)
{
  long long sum=0;
  if(lnum==unum) return true;
  long long half=(lnum+unum)/2;
  for(int i=0;i<data.size();i++){
    sum+=half/data[i];
  }
  if(sum>n) return true;
  else return false;
  
}
int main()
{
  int ret;
  FILE *ifp,*ofp;
  int board[1000];
  long long lnum,unum;
  vector<int> mod;
  ofp=fopen("B-small-test-result.in","w");
  if((ifp=fopen("B-small-test.in","r"))!=NULL){
    fscanf(ifp,"%d",&t);
    for(int i=0;i<t;i++){
      fscanf(ifp,"%d",&b);
      fscanf(ifp,"%d",&n);
      data.clear();
      mod.clear();
      lnum=0;
      unum=1000000000000000;
      memset(board,-1,sizeof(board));
      for(int j=0;j<b;j++){
        fscanf(ifp,"%d",&num);
        data.push_back(num);
      }
      for(int j=0;j<1000;j++){
        if(solve(lnum,unum)){
          unum=(lnum+unum)/2;
        }else{
          lnum=(lnum+unum)/2;
        }
      }
      long long sum=0;
      for(int j=0;j<data.size();j++){
        sum+=lnum/data[j];
        mod.push_back(lnum%data[j]); 
      }
      cout<<sum<<" "<<lnum<<endl;
      if(sum==n){
        int smod=-1;
        int spos=-1;
        for(int j=0;j<mod.size();j++){
          if(mod[j]>=smod){
            spos=j+1;
            smod=mod[j];
          }
        }
        ret=spos;
      }else{
        int gap=n-sum;
        sort(mod.begin(),mod.end());
        int ans=mod[mod.size()-gap];
        for(int j=0;j<mod.size();j++){
          if(ans==mod[j]){
            ret=j+1;
          }
        }
      }
      fprintf(ofp,"Case #%d: %d\n",i+1,ret);
      printf("Case #%d: %d\n",i+1,ret);
    
    }
  }
  fclose(ifp);
  fclose(ofp);
}
