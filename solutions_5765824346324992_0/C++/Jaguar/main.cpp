//Javier Guzmán
//CODEJAM Round1A 2015 A
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

long long t, n, m[1000], b, ans, kint;
int tmp, tot, k, j;
double s[1000];
bool done;
pair<long long, long long> barber;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;

int gcd(int a, int b) {
   while(b){int r = a % b; a = b; b = r;}
   return a;
}
int lcm(int a, int b){
   return (a*b)/gcd(a, b);
}

int main(){
   scanf("%lld", &t);
   for(long long q=1; q<=t; q++){
      while(!que.empty()){
         que.pop();
      }
      tot=0;
      tmp=1;
      scanf("%lld%lld", &b, &n);
      for(long long i=0; i<b; i++){
         scanf("%lld", &m[i]);
         barber = make_pair(0, i+1);
         que.push(barber);
         tmp=lcm(tmp, m[i]);
         //if(m[i]>tmp) tmp=m[i];
      }
      for(int i=0; i<b; i++){
         tot+=tmp/m[i];
      }
      /*
      for(int i=0; i<b; i++){
         s[i]=s[i]/tot;
      }
      kint=0;
      for(int i=0; i<b; i++){
         k+=(n-1)*s[i];
      }
      ans=n-k;*/
      n=(n%tot);
      if(n==0) n=tot;
      for(long long i=0; i<n; i++){
         barber=que.top();
         que.pop();
         barber.first=barber.first+m[barber.second-1];
         que.push(barber);
      }
      
      printf("Case #%lld: %lld\n", q, barber.second);
   }
   return 0;
}