#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main()
{
  FILE *ifp,*ofp;
  int t,ecnt,p,num,asum,bsum,maxgap;
  vector<int> data;
  int dmax,ret,retmin;
  ofp=fopen("A-large-result.in","w");
  if((ifp=fopen("A-large.in","r"))!=NULL){
    fscanf(ifp,"%d",&t);
    for(int i=0;i<t;i++){
      data.clear();
      asum=0;
      bsum=0;
      maxgap=0;
      fscanf(ifp,"%d",&ecnt);
      for(int j=0;j<ecnt;j++){
        fscanf(ifp,"%d",&num);
        data.push_back(num);
      }
      for(int j=0;j<data.size()-1;j++){
        if(data[j]>data[j+1]) asum+=data[j]-data[j+1];
        maxgap=max(maxgap,data[j]-data[j+1]);
      }
      for(int j=0;j<data.size()-1;j++){
        bsum+=min(data[j],maxgap);
      }
      fprintf(ofp,"Case #%d: %d %d\n",i+1,asum,bsum);
      printf("Case #%d: %d %d\n",i+1,asum,bsum);
    
    }
  }
  fclose(ifp);
  fclose(ofp);
}
