#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-14;
int n;
typedef struct Vector
{
	double x,y;
	Vector(double x=0,double y=0):x(x),y(y){};
	friend Vector operator - (Vector a,Vector b) {return Vector(a.x-b.x,a.y-b.y);}
	friend Vector operator * (double b,Vector a) {return Vector(a.x*b,a.y*b);}
	friend Vector operator + (Vector a,Vector b) {return Vector(a.x+b.x,a.y+b.y);}
	friend Vector operator / (Vector a,double b) {return Vector(a.x/b,a.y/b);}
	friend bool operator == (Vector a,Vector b){return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;}
	friend bool operator < (Vector a,Vector b){//这里可能有精度问题
		return (fabs(a.x-b.x)<eps&&a.y<b.y)||a.x<b.x;}
	friend double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
	friend double cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
	friend Vector Rotate(Vector a,double th){//逆时针
		return Vector(a.x*cos(th)-a.y*sin(th),a.x*sin(th)+a.y*cos(th));
	}
}Vector;
typedef Vector Point;
double Lenth(Vector a){return sqrt(a.x*a.x+a.y*a.y);}
int dcmp(double x)
{//判断x的正负
	if(fabs(x)<eps) return 0;
	if(x<0) return -1;
	if(x>0) return 1;
}
Point LineIntersection(Point P,Vector v,Point Q,Vector w)
{//两直线交点 P+t1v和Q+t2w
	Vector u=P-Q;
	double t1=cross(w,u)/cross(v,w);
	return P+t1*v;
}
double IntersecAngle(Vector v,Vector u)
{//两向量夹角
	return acos(dot(v,u)/(Lenth(v)*Lenth(u)));
}
bool OnLine(Point a,Point s,Point t)
{//判断a在线段st上(不含端点)
	return dcmp(cross(s-a,t-a))==0&&dcmp(dot(s-a,t-a))<0;
}
bool Intersect(Point a,Point b,Point c,Point d)
{//判断线段ab和线段cd是否相交（不含端点）
	int c1=dcmp(cross(d-c,a-c)),c2=dcmp(cross(d-c,b-c)),c3=dcmp(cross(b-a,c-a)),c4=dcmp(cross(b-a,d-a));
	return c1*c2<0&&c3*c4<0;
}
double DistanceToLine(Point P,Point a1,Point a2)
{
	return fabs(cross(P-a1,a2-a1))/Lenth(a1-a2);
}
double DistanceToSegment(Point P,Point a1,Point a2)
{
	if(a1==a2) return Lenth(P-a1);
	if(dcmp(dot(P-a1,a2-a1))<0&&dcmp(dot(P-a2,a2-a1))<0) return Lenth(P-a1);
	if(dcmp(dot(P-a1,a2-a1))>0&&dcmp(dot(P-a2,a2-a1))>0) return Lenth(P-a2);
	return DistanceToLine(P,a1,a2);
}
Point a[3005];
int b[3005][2];
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int t,ca=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) if(i!=j)
            {
                int tmp1=0,tmp2=0;
                for(int k=0;k<n;k++) if(k!=i&&k!=j)
                    if(dcmp(cross(a[j]-a[i],a[k]-a[i]))>0)  tmp1++;
                    else if(dcmp(cross(a[j]-a[i],a[k]-a[i]))<0) tmp2++;
                if(j==0||(j==1&&i==0))
                {
                    b[i][0]=tmp1;
                    b[i][1]=tmp2;
                }
                else
                {
                    b[i][0]=min(b[i][0],tmp1);
                    b[i][1]=min(b[i][1],tmp2);
                }
            }
        }
        printf("Case #%d:\n",++ca);
        for(int i=0;i<n;i++)
            printf("%d\n",min(b[i][0],b[i][1]));

    }
    return 0;
}
