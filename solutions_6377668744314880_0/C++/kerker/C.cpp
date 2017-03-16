#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;


typedef struct Point{
    long long x,y;  //sometime maybe use double better
}POINT;
POINT p[30],mono[60];  //N is the vertex number , p is the original vertex, mono is convex hull vertex
int cnt,NN;  //record the convex hull's vertex top
long long cross(POINT a,POINT b,POINT c){
    return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}
int com(const void *a,const void *b)
{
    POINT c,d;
    c = *(POINT*)(a);
    d = *(POINT*)(b);
    if(c.x!=d.x)	return c.x>d.x?1:-1;
    else if(c.y!=d.y)	return c.y>d.y?1:-1;
    return 0;
}
void monotone()
{
    cnt=0;
    int i,j;
    for(i=0;i<NN;i++){
        while(cnt>=2 && cross(mono[cnt-2],mono[cnt-1],p[i])<0)  // '<=' mean you will find more point on edge
            cnt--;
        mono[cnt++]=p[i];
    }
    for(i=NN-2,j=cnt+1;i>=0;i--){
        while(cnt>=j && cross(mono[cnt-2],mono[cnt-1],p[i])<0)
            cnt--;
        mono[cnt++]=p[i];
    }
    cnt--;
}
POINT a[20];
int main()
{
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<N;i++)
            scanf(" %lld %lld",&a[i].x,&a[i].y);
        printf("Case #%d:\n",t+1);
        if(N==1 || N==2 || N==3){
            for(int i=0;i<N;i++)
                printf("0\n");
            continue;
        }
        int mask = (1<<N);
        for(int k=0;k<N;k++){
            int ans = N;
            for(int i=0;i<mask;i++){
                if(((1<<k) & i)>0)  continue;
                NN = 0;
                int tmp = 0;
                for(int j=0;j<N;j++){
                    if(((1<<j) & i)==0){
                       p[NN++] = a[j];
                    }
                }
                qsort(p,NN,sizeof(p[0]),com);
                monotone();
                int re = 0;
                for(int j=0;j<cnt;j++){
                    if(mono[j].x==a[k].x && mono[j].y==a[k].y)
                        re = 1;
                }
                if(re==1){
                    ans = min(ans,N-NN);
                }
            }
            printf("%d\n",ans);
        }
    }
    
    return 0;
}


