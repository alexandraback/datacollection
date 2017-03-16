#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
if(x < 0)return -1;
else return 1;
}
struct Point
{
double x,y;
Point(){}
Point(double _x,double _y)
{
x = _x;y = _y;
}
Point operator -(const Point &b)const
{
return Point(x - b.x,y - b.y);
}
//叉积
double operator ^(const Point &b)const
{
return x*b.y - y*b.x;
}
//点积
double operator *(const Point &b)const
{
return x*b.x + y*b.y;
}
//绕原点旋转角度B（弧度值），后x,y的变化
void transXY(double B)
{
double tx = x,ty = y;
x = tx*cos(B) - ty*sin(B);
y = tx*sin(B) + ty*cos(B);
}
};


double angle(Point a,Point b)
{
    return atan2(b.y-a.y,b.x-a.x);
}     
    
int t,n;

Point p[3011];
int ans;
vector<double>q;
int ans0[3011];
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    int i,j,k,times;
    int pp,qq;
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
         cin>>n;
         for(i=1;i<=n;i++)
         {
             cin>>p[i].x>>p[i].y;
         }
         
         if(n==1)
         {
             cout<<"Case #"<<times<<":"<<endl;
             cout<<0<<endl;
             continue;
         }
         
         
         
         for(i=1;i<=n;i++)
         {
             q.clear();
             for(j=1;j<=n;j++)
             {
                 if(i!=j)
                 {
                     q.push_back(angle(p[i],p[j]));
                     q.push_back(angle(p[i],p[j])+PI*2.0);
                     q.push_back(angle(p[i],p[j])+PI*4.0);
                 }
             }
            // q.push_back(PI*10.0);
              
              sort(q.begin(),q.end());
              
              
              //for(j=0;j<q.size();j++)
              //{
              //    cout<<q[j]<<' ';
              //}
              //cout<<")(*&^%$#"<<endl;
              
              ans=99999;
              pp=qq=0;
              while(q[pp]<PI*2.0+eps)
              {
                 // cout<<pp<<' '<<qq<<endl;
                  while(q[qq]-q[pp]+eps<PI)
                  {
                      qq++;
                  }
                  //cout<<pp<<' '<<qq<<"  !!!"<<endl;
                  ans=min(ans,qq-pp-1);
                  pp++;
              }
         
              ans0[i]=ans;
             
         }
         
         cout<<"Case #"<<times<<":"<<endl;
         
         for(i=1;i<=n;i++)
         {
            cout<<ans0[i]<<endl;
         }
    }
    
    
    return 0;
}
