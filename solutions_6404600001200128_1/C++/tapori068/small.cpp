#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
   freopen("A-large.in", "r", stdin);
   //freopen("input.in","r",stdin);
   int t;
   scanf("%d\n",&t);
   for(int j = 0; j < t; j++){
      int N,m[1000];
      long long m1, m2, sum, i, r;
      scanf("%d\n",&N);
      for(i = 0; i< N; i++)  { cin>>m[i];
         //cout<<m[i]<<" ";
      }
      //cout<<endl;
      m1 = 0;
      r = 0;
      sum = 0;
     
      for(i=1;i<N;i++){
         if(m[i-1] > m[i]) {
	     m1 += m[i-1]-m[i];
	 } else { 
             m1 += 0;

	 }
	 
	     r = m[i-1] > m[i]? (r < m[i-1]-m[i]? m[i-1]-m[i]:r):r;
             //cout<<"rate = "<<r;
      }
      //cout<<"rate = "<<r<<endl;
      m2 = 0;
      sum = 0;
      for(i=0;i<N-1;i++){
         sum = m[i];
         if(r < sum){
	   m2 += r;
	   sum -= r;
	 }
	 else  {
	     m2 += sum;
	     sum = 0;
	 }
	 
      }
      cout<<"Case #"<<j+1<<": "<<m1<<" "<<m2<<endl; 
   }

}
