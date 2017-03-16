#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
    long long operator*(const point &b)const{
        return 1ll*x*b.y-1ll*b.x*y;
    }
    point operator-(const point &b)const{
        return point(x-b.x,y-b.y);
    }
};

point xxx;

bool mmm(point a,point b){
    point aa=a-xxx,bb=b-xxx;
    if(aa.x==0 && bb.x==0)
        return aa.y>bb.y;
    if(aa.x==0)
        return aa.y>0;
    if(bb.x==0)
        return bb.y<0;
    return 1.0*aa.y/aa.x > 1.0*bb.y/bb.x;
}

int getans(point p[],int n,int x){
    int r=0;
    point a[4096];
    for(int i=0;i<n;i++)
        a[i]=p[i];
    swap(a[0],a[x]);
    xxx=a[0];
    sort(a+1,a+n,mmm);
    for(int i=1;i<n;i++
}

int main(){
    int t,tk=1;
    scanf("%d",&t);
    while(t--){
        int n;
        point p[4096];
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            p[i]=point(x,y);
        }
        printf("Case #%d:\n",tk++);
        for(int i=0;i<n;i++)
            printf("%d\n",getans(p,n,i));
    }
}

