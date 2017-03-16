#include<bits/stdc++.h>
using namespace std;

struct Point{
    long long x,y;
    Point(){}
    Point(long long x,long long y):x(x),y(y){}
}ps[4010],tmp[4010],ch[4010];

typedef Point Vector;
Vector operator+(Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator-(Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator*(Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(Vector A,double p)
{
    return Vector(A.x/p,A.y/p);
}
Vector operator*(double p,Vector A)
{
    return Vector(A.x*p,A.y*p);
}
Vector operator/(double p,Vector A)
{
    return Vector(A.x/p,A.y/p);
}
bool operator<(const Point& a,const Point& b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
long long Cross(Vector a,Vector b)
{
    //计算叉积
    return a.x*b.y-a.y*b.x;
}
int ConvexHull(Point* p,int n,Point* ch)
{
    //计算凸包，输入点数组p，个数为n，输出点数组ch，函数返回凸包顶点数
    //输入不能有重复点，函数执行完后输入点的顺序被破坏
    //如果不希望在凸包的边上有输入点，把两个<=改成<
    //在精度要求高时建议用dcmp比较
    sort(p,p+n);
    //n=unique(p,p+n)-p;
    int m=0;
    for(int i=0;i<n;i++)
    {
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0)
        m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--)
    {
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<0)
        m--;
        ch[m++]=p[i];
    }
    if(n>1)
    m--;
    return m;
}

int ans[3010];
int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d",&ps[i].x,&ps[i].y);
        }
        memset(ans,63,sizeof(ans));
        for(int i=1;i<(1<<n);i++){
            int cc=0;
            for(int j=0;j<n;j++){
                if((i>>j)&1)tmp[cc++]=ps[j];
            }
            int tot=ConvexHull(tmp,cc,ch);
            set<Point> s;
            for(int i=0;i<tot;i++){
                s.insert(ch[i]);
            }
            for(int j=0;j<n;j++){
                if(s.count(ps[j])){
                    ans[j]=min(ans[j],n-cc);
                }
            }
        }
        printf("Case #%d:\n",_);
        for(int i=0;i<n;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
