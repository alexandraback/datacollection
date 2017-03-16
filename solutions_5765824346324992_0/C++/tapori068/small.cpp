#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

int lcm(int x, int y){
   long long a = x, b= y, t, gcd, lcm;
   if(x < y) {a = y;b=x;}
  while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
 
  gcd = a;
  lcm = (x*y)/gcd;
 return lcm;
}
int main() {
   freopen("B-small-attempt0.in", "r", stdin);
   //freopen("input.in", "r", stdin);
   int t;
   scanf("%d\n",&t);
   for(int i = 0; i < t; i++){
      int B,N, m[1000];
      scanf("%d %d\n",&B,&N);
      for(int j=0;j<B;j++){
         cin>>m[j];
      }
      long long l = B>1 ? lcm(m[0], m[1]): m[0];
      for(int j=2;j<B;j++){
         l = lcm(l,m[j]);   
      }
      long long cyc = 0;
      for(int j=0;j<B;j++){
         cyc+=l/m[j];
      }
      N = N % cyc;
      long long sol = -1;
      if(N == 0 && cyc == 1) sol = 1;
      else if(N==0) N = cyc;
      else if(N <= B ) sol = N;
      int x[1000];
      //cout<<"N="<<N<<" l= "<<l<<" cyc="<<cyc<<endl;
      if(sol < 0) 
      for(int j =0; j<l;j++){
         sol  = -1;
         for(int k = 0; k<B;k++){
            if(j == 0){
               x[k] = m[k];
	       N--;
	       if(N==0){
                 sol = k+1;
		 break;
	       }
	    }else {
	       x[k]--;
	       if(x[k] ==0){
	           x[k] = m[k];
		   N--;
		   if(N == 0) {
		       sol = k+1;
		       break;
		   }
	       }
	    }
	 }
	 if(sol >0) break;
      }


     if(sol == -1) cout<<"Error"<<endl;

      cout<<"Case #"<<i+1<<": "<<sol<<endl; 
   }

}
