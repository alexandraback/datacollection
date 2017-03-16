#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define mod 100007

typedef struct point
{
    double x,y;
    int idx;
    point(double x=0,double y=0):x(x),y(y){ }
}Vector;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
Vector operator  + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator  -  (point A,point B){return Vector(A.x-B.x,A.y-B.y);  }
Vector operator  *  (Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator  /  (Vector A,double p){return Vector(A.x/p,A.y/p);}

bool operator ==  (const point& a,const point& b){return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
bool operator < (const point& a,const point& b){return a.x<b.x ||(a.x==b.x&&a.y<b.y);}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}    //点积
double length(Vector A){return sqrt(Dot(A,A));}              //向量长度
double angle(Vector A,Vector B){return acos(Dot(A,B)/length(A)/length(B));}   //两向量夹角,单位rad
double cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}   //叉积 ，大于零说明B在A的左边。小于零说明B在A的右边
double area2(point A,point B,point C){return cross(B-A,C-A);}   // 以A，B，C为顶点的三角形的有向面积的两倍

Vector rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}//rad为弧度，向量逆时针旋转rad
Vector normal(Vector A){double L=length(A);return Vector(-A.y/L,A.x/L);}     //注意特判零向量，单位化

int ConvexHull(point *p,int n,point *ch)
{
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0)  m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0)  m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}
point pos[20];
int fin[20];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
       // memset(fin,0,sizeof(fin));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)    fin[i]=INF;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&pos[i].x,&pos[i].y);
            pos[i].idx=i;
        }
        int all=(1<<n);
        for(int i=0;i<all;i++)
        {
            point p[15],ch[15];
            int tot=0;
            for(int j=0;j<n;j++)    if(i&(1<<j))    p[tot++]=pos[j];
            int m=ConvexHull(p,tot,ch);
            for(int j=0;j<m;j++)
            {
                fin[ch[j].idx]=min(fin[ch[j].idx],n-tot);
            }
           // if(i==all-1)    cout<<m<<endl;
        }
        printf("Case #%d:\n",cas++);
        for(int i=0;i<n;i++)    printf("%d\n",fin[i]);
    }
}
