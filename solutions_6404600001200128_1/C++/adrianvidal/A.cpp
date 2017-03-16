#include<bits/stdc++.h>
using namespace std;
int a[100000];
int n;

int method1(){
   int ans = 0;
   for(int i=0; i<n; i++){
      if (a[i] > a[i+1]) ans += a[i] - a[i+1];
   }
   return ans;
}

int method3(){
   bool eat = false;
   int maxval = 0;
   for(int i=0; i<n; i++){
      if (a[i]>a[i+1]){
         eat = true; break;
      }
   }
   if (!eat) return 0;
   
   int lo = 0, hi = *max_element(a,a+n);
   int minval = 0;
   for(int i=0; i<n; i++) minval += a[i];
   
   while(hi-lo>1){
      int mid = (hi+lo)/2;
      int eaten = 0;
      bool valid = true;
      for(int i=0; i+1<n; i++){
         if (a[i] > a[i+1] && a[i]-a[i+1] > mid){
            valid = false; break;
         }
         if (a[i] <= mid) eaten += a[i];
         else eaten += mid;
      }
      if (valid && eaten<minval){
         hi = mid;
         minval = eaten;
      }
      else lo = mid;
   }
   return minval;
}

int method2(){
   bool eat = false;
   int maxval = 0;
   for(int i=0; i<n; i++){
      if (a[i]>a[i+1]){
         eat = true; break;
      }
   }
   if (!eat) return 0;
   
   
   int lo = 0, hi = *max_element(a,a+n);
   int minval = 0;
   for(int i=0; i<n; i++) minval += a[i];
   
   while(hi-lo>1){
      int mid = (hi+lo)/2;
      int eaten = 0;
      cout<<mid<<": ";
      for(int i=0; i+1<n; i++){
         if (a[i] <= mid) eaten += mid;
         else eaten += a[i];
         cout<<eaten<<" ";
      }
      cout<<endl;
      if (eaten<minval){
         cout<<mid<<" "<<minval<<endl;
         hi = mid;
         minval = eaten;
      }
      else lo = mid;
   }
   return minval;
}

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      scanf("%d",&n);
      for(int i=0; i<n; i++) scanf("%d",&a[i]);
      a[n] = INT_MAX;
      int ans1 = method1();
      int ans2 = method3();
      printf("Case #%d: %d %d\n",cs+1,ans1,ans2);
   }
}