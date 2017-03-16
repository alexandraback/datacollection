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
using namespace std;

typedef long long i64;typedef int i32;

typedef i64 int__;
#define rep(i,j) for(int__ i=0;i<j;i++)
#define repeat(i,j,k) for(int__ i=(j);i<(k);i++)
#define all(v) begin(v),end(v)

const i32 INF=1<<30;//10E10

int main()
{
  int leftcase;
  int casenum=1;
  cin >> leftcase;
  while(leftcase){
    int num;
    cin>>num;
    vector<int> v(num);
    rep(i,num)cin>>v[i];

    int x=0;
    //first
    int mush=0;
    {

      repeat(i,1,num){
	if(v[i-1]>v[i])mush+=v[i-1]-v[i];
      }
      
    }
    //snd
    double rate=0;
    {
      double maxdiff=0;
      repeat(i,1,num){
	if(v[i-1]>v[i]){
	  maxdiff=max(maxdiff,(double)((v[i-1]-v[i])/10.0));
	  
	}
      }
      rate=maxdiff;
    }
    double  ans2=0;
    double left=v[0];
    repeat(i,0,num-1){
      left=v[i];
      if(left>rate*10){
	left-=rate*10;
	ans2+=rate*10;
      }
      else{
	ans2+=left;
	left=0;
      }

    }

    printf("Case #%d: %d %d\n",casenum,mush,(int)ans2);    
    leftcase--;
    casenum++;
  }
  return 0;
}
