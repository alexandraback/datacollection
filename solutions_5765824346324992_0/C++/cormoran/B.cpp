//#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<string>
#include<cmath>
#include<cassert>
#include<map>
//#include<cstdint>
using namespace std;

typedef long long i64;typedef int i32;
//typedef int64_t i64;typedef int32_t i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

i64 summan(i64 time,vector<i64> &M){
  i64 ret=0;
  rep(i,M.size()){
    ret+=time/M[i] +1;
  }

  return ret;
}

int main()
{
  i64 leftcase;
  i64 casenum=1;
  cin >> leftcase;
  while(leftcase){
    i64 N;
    i64 B;
    cin>>B;
    cin>>N;
    vector<i64> M(B);
    rep(i,B)cin>>M[i];

    i64 ans=-1;

    i64 time=1;
    while(summan(time,M)<N)time*=2;

    //ans E [time/2,time]
    i64 l=time/2,r=time;

    while(r-l>1){
      i64 m=(r+l)/2;
      if(N<=summan(m, M))r=m;
      else l=m;
    }

    
    time=r;
    vector<i64> answers;
    i64 pre=summan(r-1, M);

    //printf("pre %d sum :%d\ntime %d sum :%lld\n",time-1,summan(time-1, M),time,summan(time,M));


    if(pre==N){
      rep(i,M.size()){
	if(time%M[M.size()-i-1]==0){

	  ans=M.size()-i; 
	  break;
	}
      } 
      
    }
    else{
      rep(i,M.size()){
      if(time%M[i]==0){
	pre+=1;
	if(pre==N){
	  ans=i+1;
	  break;
	}
	
      }
    }
    }

    printf("Case #%lld: %lld\n",casenum,ans);
    leftcase--;
    casenum++;
  }
  
  return 0;
}
