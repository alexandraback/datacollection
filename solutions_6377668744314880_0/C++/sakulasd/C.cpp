#include <stdio.h>  
#include <math.h>  
#include <algorithm>  
#include <iostream> 
#include <string.h> 
using namespace std;  
const int MAXN=105;  
  
struct point  
{  
    int x,y;  
};  
point list[MAXN],list2[MAXN];  
point save[MAXN],use[MAXN];
int rec[20];
int ans[20];
int dir[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int stack[MAXN],top;  
  
int cross(point p0,point p1,point p2) //计算叉积  p0p1 X p0p2   
{  
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);  
}      
double dis(point p1,point p2)  //计算 p1p2的 距离   
{  
    return sqrt((double)(p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y));  
}      
bool cmp(point p1,point p2) //极角排序函数 ， 角度相同则距离小的在前面   
{  
    int tmp=cross(list[0],p1,p2);  
    if(tmp>0) return true;  
    else if(tmp==0&&dis(list[0],p1)<dis(list[0],p2)) return true;  
    else return false;  
}      
void init(int n) //输入，并把  最左下方的点放在 list[0]  。并且进行极角排序   
{  
    int i,k;  
    point p0;  
    list[0]=use[0]; 
    p0.x=list[0].x;  
    p0.y=list[0].y;  
    k=0;  
    for(i=1;i<n;i++)  
    {  
        list[i]=use[i];  
        if( (p0.y>list[i].y) || ((p0.y==list[i].y)&&(p0.x>list[i].x)) )  
        {  
            p0.x=list[i].x;  
            p0.y=list[i].y;  
            k=i;  
        }      
    }      
    list[k]=list[0];  
    list[0]=p0;  
      
    sort(list+1,list+n,cmp);  
}       
  
void graham(int n)  
{  
    int i;  
    if(n==1) {top=0;stack[0]=0;}  
    if(n==2)  
    {  
        top=1;  
        stack[0]=0;  
        stack[1]=1;  
    }      
    if(n>2)  
    {  
        for(i=0;i<=1;i++) stack[i]=i;  
        top=1;  
          
        for(i=2;i<n;i++)  
        {  
            while(top>0&&cross(list[stack[top-1]],list[stack[top]],list[i])<0) top--;  
            top++;  
            stack[top]=i;  
        }      
    }      
} 
int main(int argc, char const *argv[])
{
    int t,n;
    scanf("%d",&t);
    for (int TT=1;TT<=t;TT++)
    {
        memset(ans,0,sizeof(ans));
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d%d",&save[i].x,&save[i].y);
        for (int pp=1;pp<dir[n];pp++)
        {
            int h=-1;
            for (int i=0;i<n;i++) if (pp&dir[i])
            {
                h++;
                use[h]=save[i];
                rec[h]=i;
            }
            //printf("%d\n",h );
            init(h+1);
            //printf("1\n");
            graham(h+1);
            //printf("%d %d  %d\n", pp,top,h);
            for (int i=0;i<=top;i++) 
                {
                   // printf("%d %d\n", list[stack[i]].x,list[stack[i]].y);
                    for (int j=0;j<n;j++) if (save[j].x==list[stack[i]].x&&save[j].y==list[stack[i]].y&&ans[j]<h+1) ans[j]=h+1;
                }
        }
        printf("Case #%d:\n", TT);
        for (int i=0;i<n;i++) printf("%d\n", n-ans[i]);
    }
    return 0;
}