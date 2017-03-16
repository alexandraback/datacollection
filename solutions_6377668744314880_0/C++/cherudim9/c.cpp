#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <utility>

using namespace std;

int n;

class Point{

public:
  
  int x,y,id;

  Point(int _x=0, int _y=0)
    :x(_x), y(_y){}

  void read(){
    scanf("%d%d",&x,&y);
  }

  void write(){
    cout<<"("<<x<<","<<y<<")"<<endl;
  }

};

Point a[3000+10];

int f[3000+10], m, ret[3000+10],g[3000+10];

Point operator-(Point a, Point b){
  return Point(a.x-b.x, a.y-b.y);
}

bool operator<(Point a, Point b){
  return a.y<b.y || a.y==b.y && a.x<b.x;
}

long long cross(Point a, Point b){
  return (long long)a.x*b.y - (long long)a.y*b.x;
}

long long dis(Point a){
  return (long long)a.x*a.x+(long long)a.y*a.y;
}

class cmp{
public:
  bool operator()(const Point&x, const Point &y){
    return cross(x-a[0], y-a[0])>0 || cross(x-a[0], y-a[0])==0 && dis(x-a[0])<dis(y-a[0]);
  }
};

int main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);

  int TT;
  cin>>TT;
  for(int tt=1; tt<=TT; tt++){
    printf("Case #%d: \n", tt);
    cin>>n;
    for(int i=0; i<n; i++)
      a[i].read(), a[i].id=i;
    sort(a,a+n);
    sort(a+1,a+n,cmp());
    //    for(int i=0; i<n; i++) a[i].write();
    m=2;
    f[0]=0; f[1]=1;
    for(int i=2; i<n; i++){
      while( m>=2 && cross(a[i]-a[f[m-2]],a[f[m-1]]-a[f[m-2]]) >= 0 )
        m--;
      f[m++]=i;
    }
    //    cout<<m<<endl;
    //for(int i=0; i<m; i++)
    //  a[f[i]].write();
    for(int i=0; i<n; i++){
      int ans=0;
      for(int j=0; j<m; j++){
        int k;
        g[0]=2;
        g[1]=i;
        g[2]=f[j];
        for(k=(j+1)%m; k!=j; k=(k+1)%m){
          if (cross(a[f[j]]-a[i], a[f[k]]-a[i])<0)
            break;
          g[++g[0]]=f[k];
        }
        int count=0;
        for(int x=0; x<n; x++){
          count++;
          for(int y=1; y<=g[0]; y++){
            int z=y+1;
            if (z>g[0]) z=1;
            if (cross(a[g[z]]-a[g[y]], a[x]-a[g[y]])<0){
              count--;
              break;
            }
          }
        }
        ans=max(ans,count);
      }
      ret[a[i].id]=n-ans;
    }
    for(int i=0; i<n; i++)
      cout<<ret[i]<<endl;
  }

  return 0;
}
