#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pt pii
ll ccw(pii a, pii b, pii c){
   ll ans = (ll)a.first*b.second + (ll)b.first*c.second + (ll)c.first*a.second;
   ans -= (ll)a.second*b.first + (ll)b.second*c.first + (ll)c.second*a.first;
   return ans;
}

vector<pii> convexHull(vector<pii> v){
   sort(v.begin(),v.end());
   vector<pii> lower;
   for(int i=0; i<v.size(); i++){
      while(lower.size()>1 && ccw(lower[lower.size()-2],lower.back(),v[i])<0){
         lower.pop_back();
      }
      lower.push_back(v[i]);
   }
   vector<pii> upper;
   for(int i=(int)v.size()-1; i>=0; i--){
      while(upper.size()>1 && ccw(upper[upper.size()-2],upper.back(),v[i])<0){
         upper.pop_back();
      }
      upper.push_back(v[i]);
   }
   vector<pii> hull(lower);
   for(int i=1; i+1<upper.size(); i++) hull.push_back(upper[i]);
   return hull;
}

bool bet(int a, int b, int x){
   return min(a,b)<=x && x<=max(a,b);
}

bool bet(pt a, pt b, pt x){
   return bet(a.first,b.first,x.first) && bet(a.second,b.second,x.second);
}

bool onBoundary(pii p, vector<pii>& v){
   /*ll area = 0;
   for(int i=1; i+1<v.size(); i++) area += ccw(v[0],v[i],v[i+1]);
   if (area == 0){
      for(int i=0; i<v.size(); i++){
         if (ccw(v[i],v[(i+1)%v.size()],p) != 0) break;
         if (bet(v[i],v[(i+1)%v.size()],p)) return true;
      }
      return false;
   }*/
   
   for(int i=0; i<v.size(); i++){
      if (ccw(v[i],v[(i+1)%v.size()],p) == 0) return true;
   }
   return false;
}

bool out(pii p, vector<pii>& v){
   ll area = 0;
   for(int i=1; i+1<v.size(); i++) area += ccw(v[0],v[i],v[i+1]);
   if (area == 0){
      for(int i=0; i<v.size(); i++){
         if (ccw(v[i],v[(i+1)%v.size()],p) != 0) return true;
         if (bet(v[i],v[(i+1)%v.size()],p)) return false;
      }
      return true;
   }
   
   for(int i=0; i<v.size(); i++){
      if (ccw(v[i],v[(i+1)%v.size()],p) < 0) return true;
   }
   return false;
}

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int n; scanf("%d",&n);
      pii p[n];
      for(int i=0; i<n; i++) scanf("%d%d",&p[i].first,&p[i].second);
      
      int maxval[n];
      fill(maxval,maxval+n,0);
      
      for(int S=0; S<(1<<n); S++){
         vector<pii> v;
         for(int j=0; j<n; j++){
            if (!(S&(1<<j))) continue;
            v.push_back(p[j]);
         }
         vector<pii> h = convexHull(v);
         
         int outside = 0;
         for(int j=0; j<n; j++){
            if (out(p[j],h)) outside++;
         }
         for(int j=0; j<n; j++){
            if (!(S&(1<<j))) continue;
            if (onBoundary(p[j],h)) maxval[j] = max(maxval[j],n-outside);
         }
      }
      printf("Case #%d:\n",cs+1);
      for(int i=0; i<n; i++){
         printf("%d\n",n-maxval[i]);
      }
   }
}