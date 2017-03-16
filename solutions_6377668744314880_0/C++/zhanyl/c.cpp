#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const double eps=1e-6;
const int maxn=3005;
const double pi=acos(-1.0);

struct point{
    double x,y;
    void init(){
        scanf("%lf%lf",&x,&y);
    }
}f[maxn],g[maxn],p;

bool operator <(const point &a,const point &b){
    return atan2(a.x-p.x,a.y-p.y)<atan2(b.x-p.x,b.y-p.y);
}

int n;

int main(){//*
    string str_in,str_out;
    cin>>str_in>>str_out;
    freopen(str_in.c_str(),"r",stdin);
    freopen(str_out.c_str(),"w",stdout);//*/
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        printf("Case #%d:\n",Cas);
        scanf("%d",&n);
        static int i;
        for(i=0;i<n;i++)
            f[i].init();
        for(i=0;i<n;i++){
            static int num,j,k,now,ans;
            static double tmp;
            num=0;
            p=f[i];
            for(j=0;j<n;j++)
                if(i!=j)g[num++]=f[j];
            sort(g,g+num);
            ans=0;
            j=0,k=0;
            tmp=0.0;
            now=0;/*
            printf("(%.3f,%.3f)\n",p.x,p.y);
            for(int j=0;j<num;j++)
                printf("(%.3f,%.3f)",g[j].x,g[j].y);
            puts("");//*/
            while(j<n){
                //printf("%d->%d %.3f\n",j,k,tmp);
                if(tmp<pi+eps){
                    k++;
                    now++;
                    if(k==num)k=0;
                    ans=max(ans,now);
                    if(j==k)break;
                    tmp=atan2(g[k].x-p.x,g[k].y-p.y)-atan2(g[j].x-p.x,g[j].y-p.y);
                    if(tmp<-eps)tmp+=2.0*pi;
                }
                else{
                    j++;
                    if(j==n)break;
                    now--;
                    tmp=atan2(g[k].x-p.x,g[k].y-p.y)-atan2(g[j].x-p.x,g[j].y-p.y);
                    if(tmp<-eps)tmp+=2.0*pi;
                }
            }
            printf("%d\n",num-ans);
        }
    }
    return 0;
}
