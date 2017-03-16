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
int t, n, m[1000], dif, maxD, ans1, ans2;
int main(){
   scanf("%d", &t);
   for(int q=1; q<=t; q++){
      scanf("%d", &n);
      scanf("%d", &m[0]);
      maxD=ans1=ans2=0;
      for(int i=1; i<n; i++){
         scanf("%d", &m[i]);
         dif=m[i-1]-m[i];
         if(dif>maxD) maxD=dif;
         if(dif>0) ans1+=dif;
      }
      for(int i=0; i<n-1; i++){
         if(m[i]<maxD) ans2+=m[i];
         else ans2+=maxD;
      }
      printf("Case #%d: %d %d\n", q, ans1, ans2);
   }
   return 0;
}